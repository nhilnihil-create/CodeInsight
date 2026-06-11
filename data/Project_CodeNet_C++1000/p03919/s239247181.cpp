#include "bits/stdc++.h"
using namespace std;
#define FOR(i,a,b) for(int i =(a);i<(b);i++)
#define REP(i,n) for(int i=0;i<(n);i++)
#define REPm(i,n) for(int i=(n)-1;i>=0;i--)
#define REP1(i,n) for(int i=1;i<=(n);i++)
#define mp make_pair
typedef long long ll;
int main(){
    int H,W;
    int r;
    int c;
    cin >> H >> W;
    REP(i,H){
        REP(j,W){
            string s;
            cin >> s;
            if(s == "snuke"){
                r = i+1;
                c = j+1;
            }
        }
    }
    cout << (char)(64+c) << r << endl;
    return 0;
}
