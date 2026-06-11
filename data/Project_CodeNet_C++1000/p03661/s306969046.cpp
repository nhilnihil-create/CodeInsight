#include <iostream>
#include <set>
#include <vector>
#include <string>
#include <algorithm>
#include <iterator>
#include <map>
#include <utility>
#include <list>
#include <climits>
#include <bitset>
#include <numeric>

using namespace std;

#define rep(i, n) for(int i = 0; i < n; i++)
#define repi(i, n) for(auto i = (n).begin(); i != (n).end(); i++)
#define in_arr(type, a, n) copy_n(istream_iterator<type>(cin), n, (a).begin());
#define ll long long int

int main(){
    int n;
    cin >> n;
    vector<ll> a(n);
    ll ans = LLONG_MAX;
    in_arr(ll, a, n);
    ll s = 0;
    ll b = accumulate(a.begin(), a.end(), (ll)0);
    // bear
    for(int i = 0; i < n - 1; i++){
        s += a[i];
        b -= a[i];
        if(abs(s - b) < ans){
            ans = abs(s - b);
        }
        //ans = min(ans, abs(s - b));
    }
    cout << ans << endl;
    return 0;
}
