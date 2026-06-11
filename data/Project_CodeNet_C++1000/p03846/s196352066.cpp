#include <bits/stdc++.h>
using namespace std;

//long long型(64bit整数)
typedef long long ll;

#define MOD 1000000007ll

int main(){
    int n;
    cin >> n;
    int a[110000];
    for(int i=0; i<n; i++){
        cin >> a[i];
    }
    sort(a, a+n);

    ll ans = 0;
    if(n % 2 == 0){
        bool isok = true;
        for(int i=0; i<n; i++){
            if(i % 2 == 0){
                if(a[i] != i+1) isok = false;
            }else{
                if(a[i] != i) isok = false;
            }
        }
        if(isok){
            ans = 1ll;
            for(int i=1; i<=n/2; i++){
                ans = ans * 2ll % MOD;
            }
        }
    }else{
        bool isok2 = true;
        for(int i=0; i<n; i++){
            if(i % 2 == 0){
                if(a[i] != i) isok2 = false;
            }else{
                if(a[i] != i+1) isok2 = false;
            }
        }
        if(isok2){
            ans = 1ll;
            for(int i=1; i<=n/2; i++){
                ans = ans * 2ll % MOD;
            }
        }
    }
    cout << ans << endl;
    return 0;
}