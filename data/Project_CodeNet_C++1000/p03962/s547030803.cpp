#include<bits/stdc++.h>
using namespace std;
using ll = long long;

int main(void){
    int a,b,c;
    cin >> a >> b >> c;
    int ans;
    if(a==b && a==c) ans = 1;
    else if(a!=b && b!=c && c!=a) ans = 3;
    else ans = 2;
    cout << ans << endl;
}