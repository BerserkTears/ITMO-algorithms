#include <vector>
#include <fstream>

using namespace std;

struct Node {
    int key = -1;
    char color = 1;
    vector<Node *> links;
};

void DFS(vector<int> &result, Node *current, bool &cycle) {
    current->color = 2;
    for (Node *link: current->links) {
        if (link->color == 2) {
            cycle = true;
            break;
        }
        if (link->color == 1){
            DFS(result, link, cycle);
        }
    }
    current->color = 3;
    result.push_back(current->key);
}

void Topsort(vector<int> &result, vector<Node> &graph, bool &cycle) {
    for (Node &node: graph) {
        if (cycle){
            break;
        }
        if (node.color == 1) {
            DFS(result, &node, cycle);

        }
    }
}

int main() {
//    ifstream fin("input.txt");
//    ofstream fout("output.txt");
    ifstream fin("topsort.in");
    ofstream fout("topsort.out");
    int n, m;
    fin >> n >> m;
    vector<Node> graph(n);
    for (int i = 0; i < m; ++i) {
        int j, k;
        fin >> j >> k;
        graph[j - 1].links.push_back(&graph[k - 1]);
    }
    for (int i = 0; i < n; i++) {
        graph[i].key = i;
    }
    vector<int> result;
    bool cycle = false;
    Topsort(result, graph, cycle);
    if (cycle){
        fout << -1;
    } else {
        for (int i = result.size() - 1; i >= 0; --i) {
            fout << result[i] + 1 << " ";
        }
    }
    fout.close();
    return 0;
}