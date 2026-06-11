#include <bits/stdc++.h>
#include <vector>
#include <queue>
using namespace std;
typedef long long LL;
#define REP(i,n) for(int i=0;i<n;i++)
#define FOR(i,a,b) for(int i=(a);i<(b);++i)

int main(){
    int N;
    cin >> N;
    string s, t;
    cin >> s;
    cin >> t;

    int ans = 2*N;

    for(int j=0; j<N; j++){
        string s_suf = s.substr(j,N-j);
        string t_pre = t.substr(0,N-j);
        if(s_suf == t_pre){
            ans -= (N-j);
            break;
        }
    }

    cout << ans << endl;
    return 0;


}