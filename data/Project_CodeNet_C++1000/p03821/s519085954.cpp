#include <iostream>
#include <vector>
#include <algorithm>
#include <functional>
#include <cmath>
#include <map>
#include <queue>
#include <string>

#define reps(i,s,n) for(int (i) = (s); (i) < (n); (i)++)
#define rep(i,n) reps(i,0,n)
using namespace std;
using ll = long long;
using pii = pair<int,int>;
using vi = vector<int> ;
using vl = vector<ll>;

int main(){
    int n;
    ll ans = 0;
    cin >> n;
    vl a(n),b(n);
    
    rep(i,n){
        cin >> a[i] >> b[i];
    }
    ll tmp = 0;
    for(int i = n-1;i >= 0;i--){
        
        if((a[i]+ans) % b[i] != 0){
            tmp = b[i] - ((a[i]+ans) % b[i]);
            //cout << i << " " << tmp << endl;
            ans += tmp;
        }
    }

    cout << ans << endl;
    return 0;
}
