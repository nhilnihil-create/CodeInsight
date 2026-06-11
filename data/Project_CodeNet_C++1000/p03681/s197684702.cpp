#include<bits/stdc++.h>
// sakib malik
#define MOD (int)(1e9 + 7)
using namespace std;

long long fact(int n){
    long long ans = 1;
    for(long long i = 1; i <= n; i++){
        ans = (ans * i%MOD)%MOD;
    }
    return ans;
}

int main(){
    int n, m;
    cin >> n >> m;
    int total = (m + n);
    if(!(total&1)){
        if(max(m, n) > total/2){
            cout << 0;
            return 0;
        }
        long long ans = ((long long)(fact(total / 2) * fact(total / 2))%MOD * 2ll)%MOD;
        cout << ans;
    }
    else{
        if(max(m, n) > (total + 1)/2){
            cout << 0;
            return 0;
        }
        int a = min(m, n);
        int b = max(m, n);
        long long ans = ((long long)fact(a) * fact(b))%MOD;
        cout << ans;
    }


}