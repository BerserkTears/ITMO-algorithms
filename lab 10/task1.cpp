#include <fstream>
#include "vector"

using namespace std;

struct Node {
    vector<int> connected_vertices;
};

int main() {
    ifstream fin("input.txt");
    ofstream fout("output.txt");
    int n, m;
    fin >> n >> m;
    vector<Node> graph(n);
    for (int i = 0; i < m; i++) {
        int j, k;
        fin >> j >> k;
        graph[j - 1].connected_vertices.push_back(k - 1);
        graph[k - 1].connected_vertices.push_back(j - 1);
    }
    for (int i = 0; i < n; i++){
        fout << graph[i].connected_vertices.size() << " ";
    }
    fout.close();
    return 0;
}