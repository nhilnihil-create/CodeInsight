#include<bits/stdc++.h>
using namespace std;
#define N (int)(1e5+7)
#define inf (int)(1e9+7)
#define INF (long long) (1e18+7)
#define fastio ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
const int M = (int)(2e6 + 239);


void solve(){
    string s;
    cin>>s;
    int n=(int)s.size();
    for(int i=0;i<n-1;i++){
        if(s[i] == s[i+1]){
            cout<<i+1<<" "<<i+2<<'\n';
            return;
        }
    }
    for(int i=0;i<n-2;i++){
        if(s[i] == s[i+2]){
            cout<<i+1<<' '<<i+3<<'\n';
            return;
        }
    }
    cout<<"-1 -1\n";
    return;
}
int main(){
    fastio;
    solve();
    return 0;
}