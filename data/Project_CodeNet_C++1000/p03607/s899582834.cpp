#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); ++i)
#define per(i,n) for (int i = (n)-1; i >=0; --i)
using namespace std;
using ll = long long;
using vi = vector<int>;
using vv = vector<vi>;

int main(){
    int n;cin>>n;
    int a;
    map<int,int> m;
    
    rep(i,n){
        cin>>a;
        m[a]++;
    }
    
    int ans = 0;
    
    for(auto p: m){
        if(p.second%2==1)ans++;
    }
    
    cout << ans <<endl;
    
    return 0;
}