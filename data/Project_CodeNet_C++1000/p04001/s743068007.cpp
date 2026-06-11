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
    cin >> s;
    int n=s.size();
    ll ans=0;
    for(int bit=0;bit<(1<<n);++bit){
        ll res=0;
        for(int i=0;i<n;++i){
            if(bit&(1<<i)){
                ans+=res;
                res=0;
            }
            res*=10;
            res+=stoi(s.substr(i,1));
        }
        ans+=res;
    }
    
    cout << ans/2 << "\n";
    return 0;
}   