#include <cstdio>
#include <cstring>
#include <algorithm>
#include <iostream>
#include <vector>
#include <queue>

using namespace std;

typedef long long ll;

const int mod = 1e9 + 7;
const int N = 30;

const int dx[4] = {1, 0, -1, 0};
const int dy[4] = {0, 1, 0, -1};

struct State{
    int x, y, s;
    State(){}
    State(int x, int y, int s): x(x), y(y), s(s) {}
};

int w, h, ocnt;
char str[N][N];
int idx[N][N];
pair<int, int> start;
int dis[N][N][2000];

inline bool inRange(int x, int y){
    return x >= 0 and x < w and y >= 0 and y < h and str[x][y] != 'x';
}
void bfs(){
    queue<State> Q;
    memset(dis, -1, sizeof(dis));
    dis[start.first][start.second][0] = 0;
    Q.push(State(start.first, start.second, 0));
    while(Q.size()){
        int x = Q.front().x, y = Q.front().y, s = Q.front().s;
        Q.pop();
        if(s + 1 == (1 << ocnt)){
            printf("%d\n", dis[x][y][s]);
            return;
        }
        for(int i = 0; i < 4; ++i){
            int ox = x + dx[i], oy = y + dy[i];
            if(!inRange(ox, oy)) continue;
            int os = idx[ox][oy] != -1 ? s | (1 << idx[ox][oy]) : s;
            if(dis[ox][oy][os] == -1){
                dis[ox][oy][os] = dis[x][y][s] + 1;
                Q.push(State(ox, oy, os));
            }
        }

    }
    printf("-1\n");
}
int main(){
    //scanf("%d %d", &h, &w);
    h=10,w=10;
    for(int i = 0; i < w; ++i) scanf("%s", str[i]);
    memset(idx, -1, sizeof(idx));
    ocnt = 0;
    for(int i = 0; i < w; ++i)
        for(int j = 0; j < h; ++j){
            if(str[i][j] == 'V') start = make_pair(i, j);
            else if(str[i][j] == 'D') idx[i][j] = ocnt++;
        }
    bfs();
    cout<<ocnt;
    return 0;
}

/*
...D.....D
.D...D....
..........
....D...D.
..........
.D........
.......D..
..........
......D...
V.D.....D.
*/

