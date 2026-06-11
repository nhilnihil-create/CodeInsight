#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define rep(i, srt, end) for (long long i = (srt); i < (long long)(end); i++)

int main(){
    ll n;
    cin >> n;
    deque<ll> b;
    rep(i, 0, n){
        ll a; cin >> a;
        if(i % 2 == 0) b.push_back(a);
        else b.push_front(a);
    }
    if(n % 2 == 1){
        rep(i, 0, n){
            cout << b.back() << " ";
            b.pop_back();
        }
    }else{
        rep(i, 0, n){
            cout << b.front() << " ";
            b.pop_front();
        }
    }
    cout << endl;
    return 0;
}