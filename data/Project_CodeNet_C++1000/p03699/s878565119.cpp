#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using Graph = vector<vector<int>>;

const ll LINF = 1e18;
const int INF = 1e9;
const ll MOD = 1000000007;

template<class T> inline bool chmin(T& a, T b){
    if(a > b){
        a = b;
        return true;
    }
    return false;
}
template<class T> inline bool chmax(T& a, T b){
    if(a < b){
        a = b;
        return true;
    }
    return false;
}

int main(){

    int n;
    cin >> n;
    vector<int> v(n);
    int sum = 0;
    for(int i = 0; i < n; i++){
        cin >> v[i];
        sum += v[i];
    }
    if(sum%10 != 0){
        cout << sum << endl;
    }
    else{
        bool ok = false;
        sort(v.begin(), v.end());
        for(int i = 0; i < n; i++){
            if((sum - v[i])%10 != 0){
                sum -=v[i];
                ok = true;
                break;
            }
        }
        if(ok) cout << sum << endl;
        else cout << 0 << endl;
    }

    return 0;
}
