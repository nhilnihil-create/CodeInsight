#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
using Graph = vector<vector<int>>;
const int INT_INF = 1001001001;

int main(){
    int n,k;
    cin >> n >> k;
    vector<int> L(n);
    for(int i=0;i<n;i++){
        cin >> L[i];
    }
    sort(L.begin(),L.end(),greater<int>());
    int ans = 0;
    for(int i=0;i<k;i++){
        ans += L[i];
    }
    cout << ans << endl;
}