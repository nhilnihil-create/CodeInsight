#include <bits/stdc++.h>

#define ll long long int
#define ld long double
#define DEFAULT_MIN 10000000
#define DEFAULT_MAX -10000000
#define PRECISION 15
using namespace std;

ll lcm(ll n1, ll n2);
ll gcd(ll n1, ll n2);

int main(){
    int n;
    cin >> n;
    ll num[n];
    for(int i=0; i<n; i++){
        cin >> num[i];
    }
    ll ans = 1;
    for(int i=0; i<n; i++){
        if(ans < num[i]){
            ans = lcm(num[i], ans);
        }
        else{
            ans = lcm(ans, num[i]);
        }
    }
    cout << ans << endl;
    return 0;
}

ll lcm(ll n1, ll n2){
    return n1 / gcd(n1, n2) * n2;
}

ll gcd(ll n1, ll n2){
    if(n1 % n2 == 0){
        return n2;
    }
    else{
        return gcd(n2, n1%n2);
    }
}
