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
    int ans = 0;
    
    rep(i,n){
        cin>>a;
        if(a%2)ans++;
    }
    
    puts(ans%2==0 ? "YES":"NO");
    
    return 0;
}

