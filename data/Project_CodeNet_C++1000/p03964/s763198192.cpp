#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
    int N; cin >> N;
    ll t, a; cin >> t >> a;
    for (int i = 1; i < N; i++)
    {
        ll tt, ta; cin >> tt >> ta;
        if(tt<t || ta <a){
            ll m = max((t+tt-1)/tt, (a+ta-1)/ta);
            t = tt *=m;
            a = ta *=m;
            //cout << t << " " << a << endl;
        } else{
            t = tt;
            a = ta;
        }
        
    }
    cout << t+a << endl;
}