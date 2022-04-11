#include "fstream"
#include "vector"

using namespace std;

struct Node {
    int group = 2;
    vector<Node *> links;
};

bool IsBipartite(Node &current) {
    for (Node *node: current.links) {
        if (node->group == 2) {
            node->group = (current.group + 1) % 2;
            if (!IsBipartite(*node)) {
                return false;
            }
        }
        if (node->group == current.group) {
            return false;
        }
    }
    return true;
}

int main() {
//    ifstream fin("input.txt");
//    ofstream fout("output.txt");
    ifstream fin("bipartite.in");
    ofstream fout("bipartite.out");
    int n, m;
    fin >> n >> m;
    if (n == 0){
        fout << "NO";
        fout.close();
        return 0;
    }
    vector<Node> graph(n);
    for (int i = 0; i < m; ++i) {
        int b, e;
        fin >> b >> e;
        if (b == e) {
            fout << "NO";
            fout.close();
            return 0;
        }
        graph[b - 1].links.push_back(&graph[e - 1]);
        graph[e - 1].links.push_back(&graph[b - 1]);
    }
    bool check = true;
    for (Node &node : graph) {
        if (node.group == 2){
            node.group = 0;
            if (!IsBipartite(node)){
                check = false;
            }
        }
    }
    if (check) {
        fout << "YES";
    } else {
        fout << "NO";
    }
    fout.close();
    return 0;
}