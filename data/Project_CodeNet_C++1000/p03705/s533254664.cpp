#include <bits/stdc++.h>
#include <math.h>
#define rep(i,n) for (int i=0;i < (n); ++i)
#define ALL(x) (x).begin(), (x).end()
using namespace std;
using ll = long long;

 
int main() {
    ll a,b,c;
    cin >> a >> b >> c;
    if(b > c || (a==1&&c!=b)){
        cout << 0 << endl;
    } else {
        cout << (c*(a-1)+b) - (b*(a-1)+c) + 1 << endl;
    }
}