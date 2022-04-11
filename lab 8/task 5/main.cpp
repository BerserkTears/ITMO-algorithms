#include <fstream>
#include <vector>
#include <queue>

using namespace std;

void Bfs(int start, vector<int> &distances, vector<vector<int>> &list){
    vector<bool> colors(list.size(), false);
    queue<int> Q;
    int distance = 0;
    distances[start] = distance;
    Q.push(start);
    while(!Q.empty()){
        int current = Q.front();
        Q.pop();
        distance = distances[current] + 1;
        for (int i = 0; i < list[current].size(); ++i) {
            if (!colors[list[current][i]]){
                Q.push(list[current][i]);
                distances[list[current][i]] = distance;
                colors[list[current][i]] = true;
            }
        }
        colors[current] = true;
    }
}

int main() {
    ifstream fin("pathbge1.in");
    ofstream fout("pathbge1.out");
    int n, m;
    fin >> n >> m;
    vector<vector<int>> list(n, vector<int>());
    vector<int> distances(n, 0);
    for (int i = 0; i < m; ++i) {
        int j, k;
        fin >> j >> k;
        list[j - 1].push_back(k - 1);
        list[k - 1].push_back(j - 1);
    }
    Bfs(0, distances, list);
    for(int distance : distances){
        fout << distance << " ";
    }
    fout.close();
    return 0;
}