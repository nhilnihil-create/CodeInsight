#include <bits/stdc++.h>
using namespace std;
using ll = long long;

const ll INF = 1001001001;
const ll mod = 1000000007;

int main(){
    int n; cin >> n;
    vector<int> a(n);
    vector<int> ans(100002);
    for(int i = 0; i < n; i++){
        cin >> a[i];
        for(int j = -1; j <= 1; j++){
            if(a[i] + j < 0) continue;
            ans[a[i] + j]++;
        }
    }
    cout << *max_element(ans.begin(), ans.end()) << endl;
}