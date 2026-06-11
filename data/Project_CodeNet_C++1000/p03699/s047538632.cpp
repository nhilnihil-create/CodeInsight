#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define all(v) (v).begin(),(v).end()
#define out(a) cout << (a) << endl
using namespace std;
using ll = long long;
int main(){
    int n;
    cin >> n;
    vector<int> vec(n);
    rep(i, n) cin >> vec[i];
    sort(all(vec));
    int sum = 0;
    rep(i, n){
        sum += vec[i];
    }
    if (sum % 10 != 0){
        out(sum);
        return 0;
    }
    for (int i=0; i<n; i++){
        if (vec[i] % 10 != 0){
            sum -= vec[i];
        }
        if (sum % 10 != 0){
            break;
        }
    }
    if (sum % 10 != 0){
        out(sum);
    }
    else out(0);
    return 0;
}