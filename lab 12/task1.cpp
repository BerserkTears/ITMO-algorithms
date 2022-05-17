#include <fstream>
#include <algorithm>
#include <iostream>
#include "vector"

#define INF INT_MAX
#define MINF INT_MIN

using namespace std;

vector<int> FindLIS(vector<int> &given){
    int size = (int)given.size();
    vector<int> d(size + 1, INF), pos(size + 1), prev(size);
    long length = 0;
    pos[0] = -1;
    d[0] = MINF;
    for (int i = 0; i < size; ++i) {
        long j = upper_bound(d.begin(), d.end(), given[i]) - d.begin();
        if(d[j - 1] < given[i] && given[i] < d[j] && (d[j - 1] - given[i]) % 2 != 0){
            d[j] = given[i];
            pos[j] = i;
            prev[i] = pos[j - 1];
            length = max(length, j);
        }
    }
    vector<int> answer;
    int p = pos[length];
    while (p != -1){
        answer.push_back(given[p]);
        p = prev[p];
    }
//    reverse(answer);
    return answer;
}

int main() {
    ifstream fin("input.txt");
    ofstream fout("output.txt");
    int n;
    fin >> n;
    vector<int> given(n), answer;
    for (int i = 0; i < n; ++i) {
        fin >> given[i];
    }
    answer = FindLIS(given);
    fout << answer.size() << endl;
    for (long i = (long)answer.size() - 1; i >= 0; i--) {
        fout << answer[i] << " ";
    }
    fout.close();
    return 0;
}