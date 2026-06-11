#include<bits/stdc++.h>
#define watch(x) cout << (#x) << " is " << (x) << endl
typedef long long ll;
using namespace std;
int static fast = [](){
  ios::sync_with_stdio(false);
  cin.tie(0); cout.tie(0); return 0;
}();

int main() {
    int n;
    cin >> n;
    vector<int> arr(n, 0);
    for(auto& val: arr)
        cin >> val;
    vector<int> cpy = arr;
    sort(cpy.begin(), cpy.end());
    unordered_map<int, int> pos;
    for(int i = 0; i < cpy.size(); i++)
        pos[cpy[i]] = i;
    int ans = 0;
    for(int i = 0; i < n; i++) {
        if (pos[arr[i]] % 2 != i % 2)
            ans += 1;
    }
    cout << ans/2 <<endl;
    return 0;
}


