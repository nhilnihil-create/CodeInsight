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

    int n;
    cin >> n;
    if(n == 1){
        cout << 1 << endl;
        return 0;
    }
    int cnt = 0;
    int ans = 0;
    for(int i = 1; i <= n; i++){
        int tmp = func(i);
        if(cnt < tmp){
            cnt = tmp;
            ans = i;
        }
    }
    cout << ans << endl;

    return 0;
}