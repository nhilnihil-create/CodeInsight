#include<bits/stdc++.h>

using namespace std;

#define all(x) (x).begin(),(x).end()

using ll = long long;
using P = pair<int,int>;
using mp =  map<string,int>;

const int MOD = 1e9 + 7;
const int INF = 1001001001;

int main(void){

    int n, k, l[55];
    cin >> n >> k;

    for(int i = 0; i < n; ++i){
        cin >> l[i];
    }

    sort(l, l+n, greater<int>());
    int ans = 0;
    for(int i = 0; i < k; ++i){
        ans += l[i];
    }

    cout << ans << "\n";

    return 0;
}
