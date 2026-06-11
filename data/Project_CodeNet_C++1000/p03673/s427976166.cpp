#include<bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define put(i) cout<<fixed<<i<<endl
using namespace std;
using ll = long long;

int main(){
    ll n; cin >> n;
    vector<ll> a(n); rep(i,n) cin >> a[i];
    
    list<ll> b;
    bool flag = 0;
    for(int i = 0; i < n; i++){
        if(i % 2 == 0){
            b.push_back(a[i]);
        }else{
            b.push_front(a[i]);
        }
    }

    if(n % 2 == 1) reverse(b.begin(),b.end());
    
    for(auto x:b){
        cout << x << " ";
    }
    cout << endl;
}