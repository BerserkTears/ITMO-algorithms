#include <fstream>
#include "vector"

using namespace std;

int knapsack(const vector<int> &arr, int capacity) {
    vector<vector <int>> d(arr.size() + 1, vector<int>(capacity + 1));
    for (int i = 1; i <= arr.size(); ++i) {
        for (int j = 1; j <= capacity; ++j) {
            if (j >= arr[i - 1])
                d[i][j] = max(d[i -1][j], d[i - 1][j - arr[i - 1]] + arr[i - 1]);
            else
                d[i][j] = d[i - 1][j];
        }
    }
    return  d[arr.size()][capacity];
}

int main() {
//    ifstream fin("knapsack.in");
//    ofstream fout("knapsack.out");
    ifstream fin("input.txt");
    ofstream fout("output.txt");
    int s, n;
    fin >> s >> n;
    vector<int> ingots(n);
    for (int i = 0; i < n; i++)
        fin >> ingots[i];
    fout << knapsack(ingots, s);
    fout.close();
    return 0;
}