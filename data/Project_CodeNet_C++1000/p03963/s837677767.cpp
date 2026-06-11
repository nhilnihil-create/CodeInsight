#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned long ul;

int main(){
    ll n, k;
    cin >> n >> k;
    ll j = k;
    for (int i = 1; i < n; i++)
        j *= (k-1);
        cout << j << endl;
        return 0;
        
}