#include <fstream>
#include "vector"

using namespace std;

int INF = INT_MAX;

struct Edge {
    int end;
    int weight;
};


struct Node {
    int key = 0;
    int distance = INF;
    bool added = false;
    vector<Edge> links;
};

int Spanning_tree_weight(vector<Node> &graph) {
    int weight = 0;
    int amount = 1, size = (int) graph.size();
    if (size == 0) {
        return 0;
    }
    graph[0].added = true;
    int minV = 0;
    int prevV = 0;
    while (amount < size) {
        int min = INF;
        int curV = minV;
        for (Edge &edge: graph[curV].links) {
            if (!graph[edge.end].added && edge.end != curV) {
                int distance = edge.weight;
                if (distance < graph[edge.end].distance) {
                    graph[edge.end].distance = distance;
                }
                if (graph[edge.end].distance < min) {
                    min = graph[edge.end].distance;
                    minV = edge.end;
                }
            }
        }
        if (minV == curV) {
            minV = prevV;
        } else {
            weight += min;
            graph[minV].added = true;
            amount++;
            prevV = curV;
        }
    }
    return weight;
}

int main() {
    ifstream fin("input.txt");
    ofstream fout("output.txt");
//    ifstream fin("spantree3.in");
//    ofstream fout("spantree3.out");
    int n, m;
    fin >> n >> m;
    vector<Node> graph(n);
    for (int i = 0; i < m; ++i) {
        int start, end, weight;
        fin >> start >> end >> weight;
        Edge edge{end - 1, weight}, edge_back{start - 1, weight};
        graph[start - 1].links.push_back(edge);
        graph[end - 1].links.push_back(edge_back);
    }
    for (int i = 0; i < n; ++i) {
        graph[i].key = i;
    }
    fout << Spanning_tree_weight(graph);
    fout.close();
    return 0;
}