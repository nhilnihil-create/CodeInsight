#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0; i<(n); i++)
#define all(v) (v).begin(),(v).end()
using ll = long long;
using P = pair<int, int>;

int main(){
    int n;
    cin >> n;
    int mul4 = 0;
    int even = 0;
    rep(i, n) {
        int a;
        cin >> a;
        if (a%4==0) mul4++;
        if (a%2==0) even++;
    }
    int b1 = n-even;
    int b2 = even-mul4;
    int b4 = mul4;
    if (b4+1>=b1+(b2>0)*1) puts("Yes");
    else puts("No");
    return 0;
}