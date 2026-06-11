#include <bits/stdc++.h>
#define ll long long
using namespace std;
#define rep(i, n) for (int i = 0; i < n; i++)
#define rrep(i, n) for (int i = 1; i <= n; i++)
using P = pair <int, int>;

int main(){
    ll n,m;
    cin >> n >>m;
    if(n<m/2){
    cout << (n+(m/2))/2 <<endl;}
    else cout << m/2 <<endl;
    }