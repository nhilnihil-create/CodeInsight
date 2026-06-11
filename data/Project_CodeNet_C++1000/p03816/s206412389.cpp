#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
using P = pair<int,int>;

int main(){
    ll n;
    cin >> n;
    vector<int> ns(n);
    rep(i, n){
        cin >> ns.at(i);
    }
    sort(ns.begin(), ns.end());
    int sum = 0;
    rep(i, n-1) if(ns.at(i) == ns.at(i+1)) sum++;
    int k = 0;
    int max = 0;
    rep(i, ns.size()-1){
        if(ns.at(i) == ns.at(i+1)){
            k += 1;
            if(max < k){
                max = k;
            }
        }else{
            k = 0;
        }
    }
/*    if(sum == 1) max = 1;
    if(sum - max*2 < 0){
        n += (sum - max*2);
    }
    cout << sum << endl;
    cout << max << endl;
*/    cout << n - sum - sum%2 << endl;
    return 0;
}