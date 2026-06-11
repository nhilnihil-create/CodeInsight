#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
using vi=vector<int>;
using P = pair<int,int>;
using Graph = vector<vector<int>>;

int main(){
    cin.tie(0);
    ios::sync_with_stdio(false);
    
    string s;
    string t="WB";
    cin >> s;
    int n=s.size();
    int c=0,ans=0;
    if(s[0]=='B') c=1;
    rep(i,n){
        if(s[i]==t[c]) continue;
        else{
            if(t[c]=='W') c=1;
            else c=0;
            ++ans;
        }
    }
    
    cout << ans << "\n";
    return 0;
}   