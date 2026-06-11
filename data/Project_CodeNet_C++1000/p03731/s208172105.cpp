#include <iostream>
#define rep(i, n) for(int i = 0; i < (n); i++)
using namespace std;
using ll = long long;
using P = pair<int, int>;

int main(){
    int n;
    ll t;
    cin >> n >> t;
    ll tt[n], sum = 0;
    rep(i, n) cin >> tt[i];
    rep(i, n-1){
        sum += min(tt[i+1] - tt[i], t);
    }
    sum += t;
    cout << sum << endl;
    return 0;
}