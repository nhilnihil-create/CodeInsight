#include<bits/stdc++.h>
using namespace std;
using LL = long long;
LL mod = 1e9+7;

int main(){
    int N;
    cin >> N;
    vector<int> t(N+2, -1), a(N+2, -1);
    for(int i = 1;i <= N;i++)    cin >> t[i];
    for(int i = 1;i <= N;i++)    cin >> a[i];
    LL ans = 1;
    bool f = true;
    vector<int> h(N+1, -1);
    for(int i = 1;i <= N;i++){
        if(t[i] > t[i-1])  h[i] = t[i];
    }
    for(int i = N;i >= 1;i--){
        if(a[i] > a[i+1]){
            if(h[i] > 0 && a[i] != t[i])    f = false;
            else    h[i] = a[i];
        }
    }
    for(int i = 1;i <= N;i++){
        LL hm = min(a[i], t[i]);
        if(h[i] < 0)    ans *= hm;
        else if(hm < h[i])  f = false;
        ans %= mod;
    }
    if(!f)  cout << 0 << endl;
    else    cout << ans << endl;
}