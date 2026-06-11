#include <bits/stdc++.h>
#define rep(i , n) for(int i = 0; i < (int)(n); i++)
using namespace std;
using ll = long long;
int main (){
    ll x;
    cin >> x;
    cout << (x - 1) / 11 * 2 + (x - 1) % 11 / 6 + 1 << endl;
}