#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); ++i)
#define per(i,n) for (int i = (n)-1; i >=0; --i)
using namespace std;
using ll = long long;
using vi = vector<int>;
using vv = vector<vi>;

int main(){
    int n; cin>>n;
    
    int a;
    map<int,int> c;
    
    rep(i,n){
        cin>>a;
        c[a]++;
        c[a-1]++;
        c[a+1]++;
    }
    
    int ans=0;
    
    for(auto p: c){
        ans = max(ans, p.second);
    }
    
    cout << ans << endl;
    
    return 0;
}