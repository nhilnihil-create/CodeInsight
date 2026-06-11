#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

const int N = 2e3+10;

const int mod = 1e9+7;

//R , L , D , U
string dr = "RLDU";
int dx[]{1 , -1 , 0 , 0};
int dy[]{0 , 0 , -1 , 1};

int sx , sy;
int tx , ty;
string ans = "";
bool vis[N][N];
bool act[N][N];
pair < int , int > from[N][N];
char is[N][N];


void bfs(int a , int b , int c , int d){
    for(int i = 0; i < N; i++)
        for(int j = 0; j < N; j++){
            from[i][j] = {0 , 0};
        }
    bool reach;
    memset(vis , 0 , sizeof vis);
    queue < pair < int , int > > q;
    q.push({a , b});
    while(q.size()){
        int x = q.front().first;
        int y = q.front().second;
        q.pop();
        if(x == c && y == d){
            break;
        }
        vis[x][y] = 1;
        for(int d = 0; d < 4; d++){
            int X = dx[d] + x;
            int Y = dy[d] + y;
            if(X >= 0 && Y >= 0 && X < N && Y < N && !vis[X][Y] && !act[X][Y]){
                    from[X][Y].first = x;
                    from[X][Y].second = y;
                    is[X][Y] = dr[d];
                    vis[X][Y] = 1;
                    q.push({X , Y});
            }
        }
    }
    string cur;
    int X = c , Y = d;
    while(abs(X - a) + abs(Y - b) != 0){
        cur = is[X][Y] + cur;
        act[X][Y] = 1;
        pair < int , int > p = from[X][Y];
        X = p.first;
        Y = p.second;
    }
    act[a][b] = 0;
    act[c][d] = 0;
    ans += cur;
    //system("PAUSE");
}

int main() {
    scanf("%d%d%d%d" , &sx , &sy , &tx , &ty);
    sx += 1e3+5;
    sy += 1e3+5;
    tx += 1e3+5;
    ty += 1e3+5;
    bfs(sx , sy , tx , ty);
    bfs(tx , ty , sx , sy);
    bfs(sx , sy , tx , ty);
    bfs(tx , ty , sx , sy);
    printf("%s\n" , ans.c_str());
    return 0;
}
