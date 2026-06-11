#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0; i<(n); i++)
#define all(v) (v).begin(),(v).end()
using ll = long long;
using P = pair<int, int>;

int main(){
    int n;
    cin >> n;
    vector<int> a(n);
    int x4 = 0, x2 = 0;
    rep(i, n) {
        cin >> a[i];
        if (a[i]%4==0) {
            x4++;
        }
        if (a[i]%2==0) {
            x2++;
        }
    }
    int b1 = n-x2;
    int b2 = x2-x4;
    int b4 = x4;
    if (b4>=b1+(b2>0)*1-1) puts("Yes");
    else puts("No");
    return 0;
}