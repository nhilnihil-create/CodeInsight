#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using ld = long double;

//#define int long long
//signed main(){
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int x,t;
    cin >> x >> t;
    cout << max(0,x-t) << "\n";

    return 0;
}