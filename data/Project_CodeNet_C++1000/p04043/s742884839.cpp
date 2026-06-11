#include <bits/stdc++.h>
#define io() ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0); srand(time(NULL));
 
using namespace std;

typedef long long ll;
typedef long double ld;
typedef unsigned long long ull;

signed main(){
    io();
    vector<int> v(3);
    cin >> v[0] >> v[1] >> v[2];
    sort(v.begin(), v.end());
    if(v[0] != 5 || v[1] != 5 || v[2] != 7) return cout << "NO\n", 0;
    return cout << "YES\n", 0;
    return 0;  
}