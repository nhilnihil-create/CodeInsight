#include <bits/stdc++.h>

using namespace std;
#define all(a)a.begin(),a.end()
using ll=long long;
const int INF = 1<<30;
const ll INFll =1LL<<62;
const int mod =(1e9)+7;
using P = pair<ll,ll>;

int main(){
    ll sx,sy,tx,ty;cin >>sx>>sy>>tx>>ty;
    for (int i = 0; i < tx - sx; ++i) {
        cout <<'R';
    }
    for (int i = 0; i < ty - sy; ++i) {
        cout <<'U';
    }
    for (int i = 0; i < tx - sx; ++i) {
        cout <<'L';
    }
    for (int i = 0; i < ty - sy; ++i) {
        cout <<'D';
    }
    cout <<'L';
    for (int i = 0; i <= ty - sy; ++i) {
        cout <<'U';
    }
    for (int i = 0; i <= tx - sx; ++i) {
        cout <<'R';
    }
    cout <<'D';cout <<'R';
    for (int i = 0; i <=ty - sy; ++i) {
        cout <<'D';
    }
    for (int i = 0; i <= tx - sx; ++i) {
        cout <<'L';
    }
    cout <<'U'<<endl;
    return 0;
}