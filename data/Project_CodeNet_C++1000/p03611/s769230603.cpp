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
    vector<int> v(100010);
    for(int i = 0; i < n; i++){
        int a;
        cin >> a;
        if(a-1 >= 0) v[a-1]++;
        v[a]++;
        v[a+1]++;
    }
    sort(v.rbegin(), v.rend());
    cout << v[0] << endl;

    return 0;
}
