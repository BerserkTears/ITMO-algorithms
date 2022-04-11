#include <fstream>
#include "vector"
#include <cmath>

using namespace std;

int INF = INT_MAX;

struct Node {
    int x, y;
    double distance;
    bool added;
};

double Distance(Node first, Node last) {
    return sqrt(pow((first.x - last.x), 2) +
                pow((first.y - last.y), 2));
}

double Spanning_tree_weight(vector<Node> &graph) {
    double weight = 0;
    int amount = 1, size = (int) graph.size();
    graph[0].added = true;
    int minV = 0;
    while (amount < size){
        double min = INF;
        int curV = minV;
        for (int i = 0; i < size; ++i) {
            if (!graph[i].added && i!=curV){
                double distance = Distance(graph[curV],graph[i]);
                if (distance < graph[i].distance){
                    graph[i].distance = distance;
                }
                if (graph[i].distance < min){
                    min = graph[i].distance;
                    minV = i;
                }
            }
        }
        weight += min;
        graph[minV].added = true;
        amount++;
    }
    return weight;
}

int main() {
//    ifstream fin("input.txt");
//    ofstream fout("output.txt");
    ifstream fin("spantree.in");
    ofstream fout("spantree.out");
    int n;
    fin >> n;
    vector<Node> graph(n);
    for (int i = 0; i < n; ++i) {
        fin >> graph[i].x >> graph[i].y;
        graph[i].added = false;
        graph[i].distance = INF;
    }
    fout << fixed;
    fout.precision(4);
    fout << Spanning_tree_weight(graph);
    fout.close();
    return 0;
}