#include <vector>
#include <fstream>

using namespace std;

struct Node {
    char color = 1;
    vector<Node *> links;
    int distance = 1;
};

int DFS(Node &current) {
    current.color = 2;
    int maxLength = 1;
    for (Node *link: current.links) {
        if (link->color == 1) {
            maxLength = max(DFS(*link) + 1,maxLength);
        }
        if (link->color == 3){
            maxLength = max(link->distance + 1,maxLength);
        }
    }
    current.color = 3;
    current.distance = maxLength;
    return maxLength;
}

int main() {
//    ifstream fin("input.txt");
//    ofstream fout("output.txt");
    ifstream fin("hamiltonian.in");
    ofstream fout("hamiltonian.out");
    int n, m;
    fin >> n >> m;
    vector<Node> graph(n);
    for (int i = 0; i < m; ++i) {
        int j, k;
        fin >> j >> k;
        graph[j - 1].links.push_back(&graph[k - 1]);
    }
    int maxDistance = 0;
    for (Node &node: graph){
        maxDistance = max(DFS(node),maxDistance);
    }
    if (maxDistance == n){
        fout << "YES";
    }
    else {
        fout << "NO";
    }
    fout.close();
    return 0;
}