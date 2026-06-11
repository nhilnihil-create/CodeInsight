#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i,n) for(int i = 0; i < (n); i++)
#define all(v) v.begin(), v.end()
#define MOD 1000000007
const int INF = 1LL<<30;

int main(){
    string s;
    cin>>s;
    int n=s.size();
    int ans=0;
    rep(i,n-1){
        if(s[i]!=s[i+1]) ans++;
    }

    cout<<ans<<endl;
}