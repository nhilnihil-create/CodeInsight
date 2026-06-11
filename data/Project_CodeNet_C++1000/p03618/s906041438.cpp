typedef long long ll;
#include <bits/stdc++.h>
using namespace std;

int main() {
    string a;
    std::cin >> a;
    ll n = a.length();
    
    vector<vector<ll>> sum(n+1,vector<ll>(28,0));
    
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < 28; j++) {
            sum[i+1][j] = sum[i][j];
            if( a[i]-'a' == j ) sum[i+1][j]++;
        }
    }
    
    ll res = 0;
    
    for (int i = 0; i < n; i++) {
        res += n-1-i-(sum[n][a[i]-'a']-sum[i+1][a[i]-'a']);
    }
    
    std::cout << res+1 << std::endl;
}
