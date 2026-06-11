#include <bits/stdc++.h>
#define REP(i,n) for(int i = 0; i < n; i++)
#define RREP(i, a, b) for (int i = a; i < (b); i++)
#define FOR(i, n) for (int i = n; i >= 0; i--)
using namespace std;
//R,Y,B,G
int main(){
    int h,w,d;
    cin >> h >> w >> d;
    char table[h][w];
    char color[2][2] = {{'R','Y'},{'B','G'}};
    if(d % 2 == 1){
        REP(i,h){
            REP(j,w){
            table[i][j] = (i+j) % 2 == 0? 'B':'G';
            }
        }
    }
    else{
        REP(i,h){
            REP(j,w){
                int x = j, y = -i;
                int xx = x + y;
                int yy = y - x;
                //cout << xx << yy << "\n";
                int divx = ceil(double(xx)/double(d)), divy = ceil(double(yy)/double(d));
                divx = divx % 2; divy = divy % 2;
                if(divx < 0) divx = divx + 2;
                if(divy < 0) divy = divy + 2;
                table[i][j] = color[divx][divy];
            }
        }
    }

    REP(i,h){
        REP(j,w){
            cout << table[i][j];
        }
        cout << "\n";
    }
    return 0;
}
