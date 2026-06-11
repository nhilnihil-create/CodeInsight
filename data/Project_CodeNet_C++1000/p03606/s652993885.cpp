#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
using Graph = vector<vector<int>>;
const int INT_INF = 1001001001;

int main(){
    int n;
    cin >> n;
    int ans = 0;
    for(int i=0;i<n;i++){
        int l,r;
        cin >> l >> r;
        ans += r-l+1;
    }
    cout << ans << endl;
}