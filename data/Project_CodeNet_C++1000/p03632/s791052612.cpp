#include <bits/stdc++.h>
#define ll long long
using namespace std;
#define rep(i, n) for (int i = 0; i < n; i++)
using P = pair <int, int>;



int main() {
    int a,b,c,d;
    cin >> a >> b >> c >>d;
    if(min(b,d)-max(a,c)>=0){
    cout << min(b,d)-max(a,c) << endl;}
    else cout << 0 << endl;
}