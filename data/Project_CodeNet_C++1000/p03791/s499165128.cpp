#include<bits/stdc++.h>
using namespace std;
#define ll long long
const ll mod = 1e9 + 7;
int N;
int x[100010];
ll fct[100010] = {1};

int main(){
    cin >> N;
    ll base = 1;
    for(int i = 0; i < N; i++){
         fct[i + 1] = fct[i] * (ll)(i + 1) % mod;
        cin >> x[i];
    }
    ll ans = 1;
    int cnt = 0;
    for(int i = 0; i < N; i++){
        if(cnt * 2 + 1 <= x[i]) cnt++;
        else ans = ans * (cnt + 1) % mod;
    }
    for(int i = 1; i <= cnt; i++){
        ans = ans * (ll)i % mod;
    }
    cout << ans << endl;
    return 0;
}