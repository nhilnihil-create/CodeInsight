#include <bits/stdc++.h>
#define rep(i,n) for(int i = 0;i < (n);i++)
using namespace std;
using ll = long long;
using pii = pair<int,int>;

const int INF = 2e9;

int main(){
    int n,a;
    cin >> n;
    vector<int> b(100000);
    rep(i,n){
        cin >> a;
        b[a]++;
    }
    int sum = b[0] + b[1] + b[2];
    int ans = sum;
    for(int i = 3;i < 100000;i++){
        sum += b[i];
        sum -= b[i - 3];
        ans = max(ans,sum);
    }
    cout << ans << endl;
}