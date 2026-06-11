#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;


int main(){
    ll n;
    cin >> n;
    vector<ll> a(n);
    ll sum1 = 0, sum2 = 0;
    ll diff;
    ll min_diff = 3*1e15;

    for(int i = 0; i < n; i++){
        cin >> a[i];
        sum2 += a[i];
    }
    for(int i = 0; i < n-1; i++){
        sum1 += a[i];
        sum2 -= a[i];
        min_diff = min(min_diff, abs(sum1-sum2));
    }
    cout << min_diff << endl;

    return 0;

}
