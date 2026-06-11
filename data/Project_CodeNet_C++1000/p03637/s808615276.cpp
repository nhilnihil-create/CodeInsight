#include<bits/stdc++.h>
#define rep(i, n) for (long long i = 0; i < (int)(n); i++)
#define put(i) cout<<fixed<<i<<endl
using namespace std;
using ll = long long;

int main(){
    ll n; cin >> n;
    vector<ll> a(n); rep(i,n) cin >> a[i];
    ll qur = 0, two = 0;

    for(long long i = 0; i < n; i++){
        if(a[i] % 4 == 0){
            qur++;
        }else if(a[i] % 2 == 0){
            two++;
        }
    }

    if(qur + two / 2 >= n / 2){
        put("Yes");
    }else{
        put("No");
    }
}