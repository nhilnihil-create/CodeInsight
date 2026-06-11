#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0; i<n; i++)
#define REP2(i,x,n) for(int i=x; i<n; i++)
#define ALL(n) begin(n),end(n)
struct cww{cww(){ios::sync_with_stdio(false);cin.tie(0);}}star;
const long long INF = numeric_limits<long long>::max();
int main(){
    string w;
    cin >> w;
    map<char,int>cnt;
    rep(i,w.size()){
        cnt[w[i]]++;
    }
    bool ok=true;
    rep(i,w.size()){
        if(cnt[w[i]]%2!=0)ok = false;
    }

    cout << (ok?"Yes":"No");
    return 0;
}
