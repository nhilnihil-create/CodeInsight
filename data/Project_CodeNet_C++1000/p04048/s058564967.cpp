#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
#define fo(i,n) for(int i=0;i<n;i++)

ll a,b,x,n,ans;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    cin >> n >> x;

    cout<<3*(n-__gcd(n,x));
    return 0;
}