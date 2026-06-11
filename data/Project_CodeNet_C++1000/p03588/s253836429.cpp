#include <iostream>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)

int main() {
    int n,a,b,m=0,ans=-1; cin >> n;
    rep(i,n){
        cin >> a >> b;
        if (a>m){
            m = a;
            ans = a+b;
        }
    }
    cout << ans << endl;
}