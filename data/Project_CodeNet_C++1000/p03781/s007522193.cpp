#include "bits/stdc++.h"
using namespace std;
#define FOR(i,a,b) for(int i =(a);i<(b);i++)
#define REP(i,n) for(int i=0;i<(n);i++)
#define REPm(i,n) for(int i=(n)-1;i>=0;i--)
#define REP1(i,n) for(int i=1;i<=(n);i++)
#define mp make_pair
typedef long long ll;
int main(){
    int X;
    cin >> X;
    int ans = 0;
    while(ans*(ans+1)/2 < X) ans++;
    cout << ans << endl;

    return 0;
}
