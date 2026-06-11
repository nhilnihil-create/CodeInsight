#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int main(){
    ll n;
    scanf("%lld",&n);
    ll a[n];
    ll sum = 0;
    for (int i = 0; i < n; i++){
        scanf("%lld",&a[i]);
        sum += a[i];
    }
    ll N = (ll)n*(n+1)/2;
    if (sum % N){
        printf("NO");
        return 0;
    }
    ll k = sum/N;
    ll x = a[0];
    for (int i = 0; i < n-1; i++){
        a[i] -= a[i+1];
    }
    a[n-1] -= x;
    ll ct = 0;
    for (int i = 0; i < n; i++){
        if (k+a[i] < 0 || (k+a[i])%n){
            printf("NO");
            return 0;
        }
        ct += (k+a[i])/n;
    }
    printf("YES\n");
}
