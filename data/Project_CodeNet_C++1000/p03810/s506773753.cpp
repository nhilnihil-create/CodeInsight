#include<bits/stdc++.h>
#define ll long long
using namespace std;
bool F(vector<ll> a){
    ll n = a.size();
    ll S = 0;
    for(ll i = 0; i < n; i++)
        S += a[i] - 1;
    if(S % 2 == 1) return 1;
    if(n % 2 == 0) return 0;
    ll X = S + n - 1;
    ll Y = 1;
    if(X == 0) return 0;
    while(X % 2 == 0) Y*=2, X/=2;
    ll N = 0;
    for(ll i = 0; i < n; i++)
        if(a[i] == 1 || ((a[i] % Y) && ((a[i] - 1)%Y)))
            return 0;
        else if(a[i] % Y) N++;
    if(N > 1) return 0;
    for(ll i = 0; i < n; i++){
        if(a[i]%Y){
            a[i] --;
        }
    }
    ll G = a[0];
    for(ll i = 0; i < n; i++){
        G = __gcd(G, a[i]);
    }
    for(ll i = 0; i < n; i++)
        a[i] /= G;
    if(F(a)) return 0;
    else return 1;
}
main(){
    ll n;
    cin >> n;
    vector<ll> v;
    for(ll i = 0; i < n; i++){
        ll a;
        cin >> a;
        v.push_back(a);
    }
    if(F(v)){
        cout << "First"<<endl;
    }
    else cout<< "Second"<<endl;

}
