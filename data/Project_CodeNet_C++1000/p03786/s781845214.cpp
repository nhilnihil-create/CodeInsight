#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
const ll MOD = 1000000007;
const ld PI = acos(-1);  
const ld EPS = 0.0000000001;

int main(){
    int n;  cin >> n;
    vector<ll> a(n);
    for(int i=0; i<n; i++)  cin >> a.at(i);
    sort(a.begin(), a.end());
    
    int ans=1;
    vector<ll> s(n, 0);    s[0] = a[0];
    for(int i=1; i<n; i++)
        s[i] = s[i-1]+a[i]; 

    
    for(int i=n-1; 1<=i; i--){
        if(a[i]<=2*s[i-1]) ans += 1;
        else break;
    }
    cout << ans << endl;
}