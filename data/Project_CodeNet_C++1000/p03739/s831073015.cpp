#include <iostream>
#include <vector>
#include <map>
#include <algorithm>

using namespace std;

const long MOD = 1000000007;
typedef pair<int, int> P;
typedef long long ll;

const int MAX_N = 100000005;
int n;
int a[MAX_N];

ll check(ll sum, ll ans){
    // cout << "---- " << sum << endl;
    for(int i=1; i<n; i++){
        ll t = sum + a[i];
        if((sum>=0 && t<0) || (sum<0 && t>=0)){
            sum = t;
            if(sum == 0){
                sum = 1;
                ans++;
            }
            continue;
        }

        ll at;
        if(sum >= 0) at = -1 - sum;
        else at = 1 - sum;

        // cout << i << " " << a[i] << " " << at << endl;

        ans  = ans + abs(a[i] - at);

        sum = sum + at;
    }
    // cout << ans << endl;
    return ans;
}

int main(){
    cin >> n;
    
    for(int i=0; i<n; i++){
        cin >> a[i];
    }

    ll ta, s;
    ta = a[0];
    s = 0;
    if(ta == 0){
        ta = 1;
        s = 1;
    }

    ll another;
    if(a[0] >= 0)another = -1;
    else another = 1;

    ll a1 = check(ta, s);
    ll a2 = check(another, abs(a[0]-another));

    ll ans = min(a1, a2);

    cout << ans << endl;

    return 0;
}
