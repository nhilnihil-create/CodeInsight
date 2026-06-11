#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll mod = 1e9+7;

ll solve(int n,int* t,int* a){
    int maxh[100000],h[100000];
    fill(maxh,maxh+100000,0);
    fill(h,h+100000,0);
    ll res = 1;
    bool isP = 1;

    h[0] = t[0];
    for(int i = 1;i < n;i ++){
        if(t[i]!=t[i-1]) h[i] = t[i];
        else maxh[i] = t[i];
    }
    for(int i = n-1;i >=0;i --){
        if(i==n-1||a[i]!=a[i+1]){
            if(h[i] && a[i]!=h[i]) {isP = 0;break;}
            else h[i] = a[i];

            if(maxh[i] && h[i] > maxh[i]) {isP = 0;break;}
        }else{
            if(a[i]<h[i]) {isP = 0;break;}
            else maxh[i] = min(a[i],maxh[i]);
        }
    }
    if(!isP) return 0;
    else{
        for(int i = 0;i < n;i ++){
            if(!h[i]) res = (res*maxh[i])%mod;
        }
    }
    return res;
}

int main(){
    int n,t[100000],a[100000];
    cin >> n;
    for(int i = 0;i < n;i ++){
        cin >> t[i];
    }
    for(int i = 0;i < n;i ++){
        cin >> a[i];
    }
    cout << solve(n,t,a) << endl;
    return 0;
}