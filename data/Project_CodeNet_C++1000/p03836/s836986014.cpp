#include <bits/stdc++.h>
#define rep(i, n) for(ll i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
const double PI=acos(-1);

template<typename T>
istream& operator>> (istream& is, vector<T> &vec){
    for(T& x: vec) is >> x;
    return is;
}

bool field[2005][2005];

int main(){
    ll sx = 0, sy = 0, tx = 1, ty = 2;
    cin >> sx >> sy >> tx >> ty;
    
    fill(field[0], field[2005], false);
    ll fsx = sx+1002, fsy = sy+1002, ftx = tx+1002, fty = ty+1002;
    ll loop = 0, tmpx = fsx, tmpy = fsy, destx = ftx, desty = fty, cc = 0;
    ll dy[2][4] = {{1, 0, -1, 0}, {0, -1, 0, 1}}, dx[2][4] = {{0, 1, 0, -1}, {-1, 0, 1, 0}};
    char move[2][4] = {{'U', 'R', 'D', 'L'}, {'L', 'D', 'R', 'U'}};
    
    
    while(loop != 2){
        while(tmpy != desty || tmpx != destx){
            ll ndx = abs(tmpx - destx), ndy = abs(tmpy - desty);
            bool z = false;
            rep(i, 4){
                ll dix = abs(tmpx+dx[cc%2][i] - destx), diy = abs(tmpy+dy[cc%2][i] - desty);
                if((ndx > dix || ndy > diy) && !field[tmpx+dx[cc%2][i]][tmpy+dy[cc%2][i]]){
                    tmpy += dy[cc%2][i];
                    tmpx += dx[cc%2][i];
                    field[tmpx][tmpy] = true;
                    printf("%c", move[cc%2][i]);
                    z = true;
                    break;
                }
            }
            if(!z){
                rep(i, 4){
                    if(!field[tmpx+dx[cc%2][i]][tmpy+dy[cc%2][i]]){
                        tmpy += dy[cc%2][i];
                        tmpx += dx[cc%2][i];
                        field[tmpx][tmpy] = true;
                        printf("%c", move[cc%2][i]);
                        break;
                    }
                }
            }
        }

        if(desty == fty){
            destx = fsx;
            desty = fsy;
            cc++;
        }else{
            desty = fty;
            destx = ftx;
            loop++;
            cc++;
        }
        field[destx][desty] = false;
    }
    cout << endl;

    return 0;
}