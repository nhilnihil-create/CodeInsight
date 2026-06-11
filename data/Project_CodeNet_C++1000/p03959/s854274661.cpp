#include <bits/stdc++.h>
using namespace std;

int main(){
    int n;
    cin >> n;
    long long t[n],a[n];
    for(int i=0; i<n; i++){
        cin >> t[i];
    }
    for(int i=0; i<n; i++){
        cin >> a[i];
    }
    long long t_u[n],t_l[n];
    t_u[0] = t[0];
    t_l[0] = t[0];
    for(int i=1; i<n; i++){
        if(t[i] > t[i-1]){
            t_u[i] = t[i];
            t_l[i] = t[i];
        }
        else{
            t_u[i] = t[i];
            t_l[i] = 1;
        }
    }
    long long a_u[n],a_l[n];
    a_u[n-1] = a[n-1];
    a_l[n-1] = a[n-1];
    for(int i=n-2; i>=0; i--){
        if(a[i] > a[i+1]){
            a_u[i] = a[i];
            a_l[i] = a[i];
        }
        else{
            a_u[i] = a[i];
            a_l[i] = 1;
        }
    }
    long long mod = 1000000007;
    long long ans = 1;
    for(int i=0; i<n; i++){
        long long u = min(t_u[i],a_u[i]);
        long long l = max(t_l[i],a_l[i]);
        if(u < l){
            ans = 0;
            break;
        }
        else{
            ans *= u-l+1;
            ans %= mod;
        }
    }
    cout << ans << endl;
    return 0;
}
