#include <bits/stdc++.h>
using namespace std;
using ll = long long;

const ll LINF = 1e18;
const int INF = 1e9;
const ll MOD = 1000000007;

int func(int n){
    int cnt = 0;
    while(n){
        if(n%2 == 0){
            cnt++;
            n /= 2;
        }
        else{
            break;
        }
    }
    return cnt;
}
int main(){

    int n, k;
    cin >> n >> k;
    vector<int> v(n);
    for(int i = 0; i < n; i++){
        cin >> v[i];
    }

    sort(v.rbegin(), v.rend());
    int ans = 0;
    for(int i = 0; i < k; i++){
        ans += v[i];
    }
    cout << ans << endl;
    
    return 0;
}