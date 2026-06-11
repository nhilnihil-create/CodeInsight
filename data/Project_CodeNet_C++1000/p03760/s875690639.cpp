#include <bits/stdc++.h>
using namespace std;
using Graph = vector<vector<int>>;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define pii pair<int,int>
const long long MOD=1e9+7;

int main(){
    string s,t;
    cin>>s>>t;
    rep(i,t.size()) cout<<s[i]<<t[i];
    if(s.size()-t.size()==1) cout<<s[s.size()-1];
    cout<<endl;
    return 0;
}
