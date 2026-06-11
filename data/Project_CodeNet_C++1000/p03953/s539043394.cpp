#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
const int mx = 1e5 + 5;

int tmp[mx];
void apply(int n, int *send, int *reci){
    for(int i = 0; i < n; i++){
        tmp[i] = reci[send[i]];
    }
    copy(tmp,tmp+n,reci);
}

void powperm(ll k, int n, int *p, int *ret){
    iota(ret,ret+n,0);
    for(;k;k>>=1){
        if(k&1){
            apply(n,p,ret);
        }
        apply(n,p,p);
    }
}

int ans[mx];
int basep[mx];
ll x[mx], dx[mx];
int n, m;
ll k;

int main(){
    ios_base::sync_with_stdio(false);cin.tie(0);
    cin >> n;
    for(int i = 0; i < n; i++){
        cin >> x[i];
        if(i) dx[i-1] = x[i] - x[i-1];
    }
    iota(basep,basep+n,0);
    cin >> m >> k;
    for(int i = 0, j; i < m; i++){
        cin >> j;
        swap(basep[j-2],basep[j-1]);
    }
    powperm(k,n-1,basep,ans);
    ll X = x[0];
    for(int i = 0; i < n; i++){
        cout << X << '\n';
        X += dx[ ans[i] ];
    }
}
