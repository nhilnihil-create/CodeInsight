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
    ll a,b,x;
    cin >> a >> b >> x;
    ll ans = b/x - a/x;
    if(a % x == 0){
        ans++;
    }

    cout << ans << endl;
    return 0;
}