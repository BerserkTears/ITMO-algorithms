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
            result.resize(0);
            result.push_back(link->key);
            break;
        }
        if(cycle){
            break;
        }
        if (link->color == 1) {
            DFS(result, link, cycle);
        }
    }
    if (cycle) {
        if (result[0] == current->key) {
            cycle = false;
        } else {
            result.push_back(current->key);
        }
    }
    current->color = 3;
}

void IsCycled(vector<int> &result, vector<Node> &graph, bool &cycle) {
    for (Node &node: graph) {
        if (node.color == 1) {
            DFS(result, &node, cycle);
        }
    }
}

int main() {
//    ifstream fin("input.txt");
//    ofstream fout("output.txt");
    ifstream fin("cycle.in");
    ofstream fout("cycle.out");
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
    IsCycled(result, graph, cycle);
    if (!result.empty()) {
        fout << "YES" << endl;
        fout << result[0] + 1 << " ";
        for (int i = (int)result.size() - 1; i >= 1; i--) {
            fout << result[i] + 1 << " ";
        }
    } else {
        fout << "NO";
    }
    fout.close();
    return 0;
}