#include <fstream>
#include <vector>
#include <queue>
#include "string"

using namespace std;

struct Node {
    char value = '.';
    string path ;
    int distance = -1;
    bool visited = false;
    int x = -1;
    int y = -1;
};

void Bfs(vector<vector<Node>> &labyrinth, Node *start) {
    queue<Node *> Q;
    int distance = 0;
    start->distance = distance;
    Q.push(start);
    start->visited = true;
    while (!Q.empty()) {
        Node current = *Q.front();
        Q.pop();
        distance = current.distance + 1;
        if (current.x > 0 && !labyrinth[current.x - 1][current.y].visited &&
            labyrinth[current.x - 1][current.y].value != '#') {
            Q.push(&labyrinth[current.x - 1][current.y]);
            labyrinth[current.x - 1][current.y].distance = distance;
            labyrinth[current.x - 1][current.y].visited = true;
            labyrinth[current.x - 1][current.y].path = current.path + 'U';
            if (labyrinth[current.x - 1][current.y].value == 'T') break;
        }
        if (current.y > 0 && !labyrinth[current.x][current.y - 1].visited &&
            labyrinth[current.x][current.y - 1].value != '#') {
            Q.push(&labyrinth[current.x][current.y - 1]);
            labyrinth[current.x][current.y - 1].distance = distance;
            labyrinth[current.x][current.y - 1].visited = true;
            labyrinth[current.x][current.y - 1].path= current.path + "L";
            if (labyrinth[current.x][current.y - 1].value == 'T') break;

        }
        if ((current.x < labyrinth.size() - 1) && !labyrinth[current.x + 1][current.y].visited &&
            labyrinth[current.x + 1][current.y].value != '#') {
            Q.push(&labyrinth[current.x + 1][current.y]);
            labyrinth[current.x + 1][current.y].distance = distance;
            labyrinth[current.x + 1][current.y].visited = true;
            labyrinth[current.x + 1][current.y].path = current.path + "D";
            if (labyrinth[current.x + 1][current.y].value == 'T') break;

        }
        if ((current.y < labyrinth[current.x].size() - 1) && !labyrinth[current.x][current.y + 1].visited &&
            labyrinth[current.x][current.y + 1].value != '#')  {
            Q.push(&labyrinth[current.x][current.y + 1]);
            labyrinth[current.x][current.y + 1].distance = distance;
            labyrinth[current.x][current.y + 1].visited = true;
            labyrinth[current.x][current.y + 1].path = current.path + "R";
            if (labyrinth[current.x][current.y + 1].value == 'T') break;

        }
    }
}

int main() {
    ifstream fin("input.txt");
    ofstream fout("output.txt");
    int n, m;
    fin >> n >> m;
    Node *start, *end;
    vector<vector<Node>> labyrinth(n, vector<Node>(m));
    for (int i = 0; i < n; i++) {
        string str;
        fin >> str;
        for (int j = 0; j < m; j++) {
            labyrinth[i][j].value = str[j];
            labyrinth[i][j].x = i;
            labyrinth[i][j].y = j;
            if (str[j] == 'S') {
                start = &labyrinth[i][j];
            }
            if (str[j] == 'T') {
                end = &labyrinth[i][j];
            }
        }
    }
    Bfs(labyrinth, start);
    fout << end->distance;
    if (end->distance != -1){
        fout << endl << end->path;
    }
    fout.close();
    return 0;
}