#include<bits/stdc++.h>
using namespace std;
// long ncrmodp(long n,long r,long p){
//     long ans = 1;
//     for(long i=n-r+1;i<=n;i++){
//         ans *= i;
//         ans %= p;
//     }
//     long tmp = 1;
//     for(long i=2;i<=r;i++){
//         tmp *= i;
//         tmp %= p;
//     }
//     for(long i=1;i<=p-2;i*=2){
//         if(i & p-2){
//             ans *= tmp;
//             ans %= p;
//         }
//         tmp *= tmp;
//         tmp %= p;
//     }
//     return ans;
// }
int main(){
    int n,m;
    cin >> n >> m;
    long const mod = 1e9+7;
    if(n < m)swap(n,m);   //n>=m
    long ans = 0;
    if(n==m){
        ans = 2;
        for(long i=2;i<=n;i++){
            ans *= i;
            ans %= mod;
            ans *= i;
            ans %= mod;
        }
    }else if(n-m==1){
        ans = 1;
        for(long i=2;i<=m;i++){
            ans *= i;
            ans %= mod;
            ans *= i;
            ans %= mod;
        }
        ans *= n;
        ans %= mod;
    }
    cout << ans << endl;
}