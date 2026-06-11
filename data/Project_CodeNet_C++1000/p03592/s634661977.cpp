#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using ld = long double;

//#define int long long
//signed main(){
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n,m,k;
    cin >> n >> m >> k;
    vector<bool> a((n+1)*(m+1));

    for(int i = 0; i <= n; i++) {
        for(int j = 0; j <= m; j++) {
            int tmp=i*(m-j)+(n-i)*j;
            a[tmp]=true;
        }
    }
    if(a[k]) cout << "Yes" << "\n";
    else cout << "No" << "\n";

    return 0;
}