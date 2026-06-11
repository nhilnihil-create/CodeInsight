#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> P;
const long double PI = (acos(-1));
#define rep(i, x, n) for (int i = x; i < (int)(n); i++)
#define sc(x) scanf("%d",&x)
#define scll(x) scanf("%lld",&x)
int main(){
    ll n, tv = 1, av = 1, tmp; scll(n);
    vector<int> t(n), a(n);
    rep(i, 0, n) sc(t[i]), sc(a[i]);
    rep(i, 0, n){
        tmp = max(tv/t[i]+(tv%t[i]!=0), av/a[i]+(av%a[i]!=0));
        tv = t[i]*tmp, av = a[i]*tmp;
    }
    cout << tv + av << endl;
    return 0;
}