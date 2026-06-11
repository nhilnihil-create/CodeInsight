#include <iostream>
#include <queue>
using namespace std;
typedef pair<int, int> P;

const int M = 2000;

const int dx1[4] = {1, 0, -1, 0};
const int dy1[4] = {0, 1, 0, -1};

int dx2[4], dy2[4];
char c[2002][2002];

int main()
{
    int h, w, d;
    cin >> h >> w >> d;
    for(int i = 0; i < M; i++){
        for(int j = 0; j < M; j++) c[i][j] = '.';
    }
    queue<P> que;
    if(d % 2 == 0){
        dx2[0] = d / 2;
        dx2[1] = -d / 2;
        dx2[2] = -d / 2;
        dx2[3] = d / 2;
        dy2[0] = d / 2;
        dy2[1] = d / 2;
        dy2[2] = -d / 2;
        dy2[3] = -d / 2;
        c[M / 2][M / 2 - 1] = 'R';
        c[M / 2][M / 2] = 'R';
        que.push(P(M / 2, M / 2 - 1));
        que.push(P(M / 2, M / 2));
    }
    else{
        dx2[0] = d / 2 + 1;
        dx2[1] = -d / 2;
        dx2[2] = -d / 2 - 1;
        dx2[3] = d / 2;
        dy2[0] = d / 2;
        dy2[1] = d / 2 + 1;
        dy2[2] = -d / 2;
        dy2[3] = -d / 2 - 1;
        c[M / 2][M / 2] = 'R';
        que.push(P(M / 2, M / 2));
    }
    while(que.size()){
        P p = que.front();
        que.pop();
        int x = p.first, y = p.second;
        for(int i = 0; i < 4; i++){
            int nx = x + dx2[i], ny = y + dy2[i];
            if(nx >= 0 && nx < M && ny >= 0 && ny < M && c[nx][ny] == '.'){
                if(c[x][y] == 'R'){
                    if(i % 2) c[nx][ny] = 'B';
                    else c[nx][ny] = 'G';
                }
                if(c[x][y] == 'B'){
                    if(i % 2) c[nx][ny] = 'R';
                    else c[nx][ny] = 'Y';
                }
                if(c[x][y] == 'G'){
                    if(i % 2) c[nx][ny] = 'Y';
                    else c[nx][ny] = 'R';
                }
                if(c[x][y] == 'Y'){
                    if(i % 2) c[nx][ny] = 'G';
                    else c[nx][ny] = 'B';
                }
                que.push(P(nx, ny));
            }
        }
    }
    while(que.size()) que.pop();
    for(int i = 0; i < M; i++){
        for(int j = 0; j < M; j++){
            if(c[i][j] != '.') que.push(P(i, j));
        }
    }
    while(que.size()){
        P p = que.front();
        que.pop();
        int x = p.first, y = p.second;
        for(int i = 0; i < 4; i++){
            int nx = x + dx1[i], ny = y + dy1[i];
            if(nx >= 0 && nx < M && ny >= 0 && ny < M && c[nx][ny] == '.'){
                c[nx][ny] = c[x][y];
                que.push(P(nx, ny));
            }
        }
    }
    for(int i = M / 2 - h / 2; i < M / 2 - h / 2 + h; i++){
        for(int j = M / 2 - w / 2; j < M / 2 - w / 2 + w; j++){
            cout << c[i][j];
        }
        cout << endl;
    }
}
