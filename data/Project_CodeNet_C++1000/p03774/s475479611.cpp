#include <bits/stdc++.h>
 
using namespace std;
#define repr(i,a,b) for (int i=a; i<b; i++)
#define rep(i,n) for (int i=0; i< (int) n; i++)
#define PI  3.14159265358979323846264338327950
 
int main () {
    int N , M;
    cin >> N >> M;

    vector<vector<int>>gakusei(N,vector<int>(2));
    rep(i,N){
        rep(j,2){
            cin >> gakusei[i][j];
        }
    }
    vector<vector<int>>check(M,vector<int>(2));
    rep(i,M){
        rep(j,2){
            cin >> check[i][j];
        }
    }

    rep(i,N){
        int man = 1000000000;
        int ans =55;
        rep(j,M){
            int kyori = abs(gakusei[i][0]-check[j][0]) + abs(gakusei[i][1]-check[j][1]);
            if( man > kyori ){
                man = kyori;
                ans = j+1;
            }
            

        }
        cout << ans << endl;
    }


}
