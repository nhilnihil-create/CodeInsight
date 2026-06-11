#include <bits/stdc++.h>
using namespace std;
#define finish(x) return cout << x << endl, 0
#define ll long long

int n;
vector <int> a;

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> n;
    a.resize(n);
    ll sum = 0;
    for(auto &i : a){
        cin >> i;
        sum += i;
    }
    ll s = 1LL * n * (n + 1) / 2;
    if(sum % s) finish("NO");
    ll h = sum / s;
    ll cnt = 0;
    for(int i = 0 ; i < n ; i++){
        ll d = a[i] - a[(i - 1 + n) % n] - h;
        if(d % n) finish("NO");
        cnt += abs(d / n);
    }
    if(cnt == h) cout << "YES\n";
    else cout << "NO\n";
}
