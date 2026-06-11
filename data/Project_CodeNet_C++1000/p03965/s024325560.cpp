#include <bits/stdc++.h>
using namespace std;
using Graph = vector<vector<int>>;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
const long long MOD=1000000007;
#define chmax(x,y) x=max(x,y)
#define chmin(x,y) x=min(x,y)
const int mmax=1000009;

int main(void){
    string s;
    cin>>s;
    int n=s.size();
    int p=0,g=0,ans=0;
    rep(i,n){
        if(p==g){
            g++;
            if(s[i]=='p') ans--;
        }
        else{
            p++;
            if(s[i]=='g') ans++;
        }
    }
    cout<<ans<<endl;
    return 0;
}
