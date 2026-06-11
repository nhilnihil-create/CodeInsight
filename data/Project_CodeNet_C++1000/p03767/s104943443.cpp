#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i<(int)(n);i++)
using ll= long long;

int main(){
    ll n,x,y=0;
    vector<ll> a;
    cin >> n;
    rep(i,3*n){
        cin >> x;
        a.push_back(x);//vectorへのcin
    } 
    
    sort(a.begin(), a.end(), greater<int>());

  //  rep(i, 3 * n) cout << a[i] << endl;

    rep(i,n){
        y += a[2 * i + 1];
    }
    cout << y << endl;
}