#include <bits/stdc++.h>
using namespace std;
#define REP(i, n) for(int i = 0; i < n; i++)

int main(){
    int h, w;
    cin >> h >> w;
    string S[h][w];
    REP(i, h) REP(j, w) cin >> S[i][j];

    char a;
    int b;
    REP(i, h){
        REP(j, w){
            if(S[i][j] == "snuke"){
                a = 'A' + j;
                b = i + 1;
                break;
            }
        }
    }
    cout << a << b << endl;

    return 0;
}