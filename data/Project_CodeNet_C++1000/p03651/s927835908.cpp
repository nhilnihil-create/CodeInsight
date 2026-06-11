#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
using vi=vector<int>;
using P = pair<int,int>;
using Graph = vector<vector<int>>;

int gcd(int a, int b){
    if(a%b == 0){
        return(b);
    }else{
        return(gcd(b, a%b));
    }
}

int lcm(int a, int b){
   return a * b / gcd(a, b);
}

int main(){
    cin.tie(0);
    ios::sync_with_stdio(false);
    
    int n;
    ll k;
    cin >> n >> k;
    vector<ll> a(n);
    rep(i,n) cin >> a[i];
    sort(a.begin(),a.end());
    if(a[n-1]<k){
        cout << "IMPOSSIBLE" << "\n";
        return 0;
    }
    bool ok=false,ok1=false;
    ll x=a[0];
    rep(i,n){
        x=gcd(a[i],x);
    }
    rep(i,n){
        if(a[i]%x!=0) ok=true;
        if(a[i]%2!=0) ok1=true;
    }
    if(ok && ok1){
        cout << "POSSIBLE" << "\n";
        return 0;
    }
    else{
    if(k%x==0){
            cout << "POSSIBLE" << "\n";
            return 0;
        }else{
            cout << "IMPOSSIBLE" << "\n";
            return 0;
        }
    }
}   