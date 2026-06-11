#include <iostream>
#include <vector>
#include <algorithm>
#include <map>
#define rep(i, n) for(int i = 0; i < (n); i++)
using namespace std;
using ll = long long;

ll c[51][51];

void comb_table(int n){
    for(int i = 0; i <= n; i++){
        for(int j = 0; j <= i; j++){
            if(i == j || j == 0) c[i][j] = 1LL;
            else c[i][j] = c[i-1][j-1] + c[i-1][j];
        }
    }
    return;
}

int main(){
    int n, a, b;
    cin >> n >> a >> b;
    ll v[n];
    map<ll, int> mp;
    rep(i, n){
        cin >> v[i];
        mp[v[i]]++;
    }
    sort(v, v + n);
    reverse(v, v + n);

    comb_table(n);

    double max_av = 0.0;
    int cnt = 0;
    rep(i, a){
        max_av += v[i];
        if(v[i] == v[a-1]) cnt++;
    }
    max_av /= a;

    ll pat = 0LL;
    if(cnt == a){
        for(int i = a; i <= min(b, mp[v[a-1]]); i++){
            pat += c[mp[v[a-1]]][i];
        }
    } else {
        pat += c[mp[v[a-1]]][cnt];
    }

    cout.precision(6);
    cout << fixed << max_av << endl;
    cout << pat << endl;
    return 0;
}