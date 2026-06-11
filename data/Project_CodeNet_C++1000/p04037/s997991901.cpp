#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int,int> P;

#define p_ary(ary,a,b) do { cout << "["; for (int count = (a);count < (b);++count) cout << ary[count] << ((b)-1 == count ? "" : ", "); cout << "]\n"; } while(0)
#define p_map(map,it) do {cout << "{";for (auto (it) = map.begin();;++(it)) {if ((it) == map.end()) {cout << "}\n";break;}else cout << "" << (it)->first << "=>" << (it)->second << ", ";}}while(0)

int main() {
    int n;
    cin >> n;
    vector<int> a(n);
    for (int i = 0;i < n;++i) cin >> a[i];
    sort(a.begin(),a.end());
    reverse(a.begin(),a.end());
    bool ans;
    for (int i = 0;i < n;++i) {
        if (i == n-1 || a[i+1] <= i+1) {
            int cnt = 0;
            for (int j = i+1;j < n;++j) if (a[j] > i) cnt++;
            if (cnt%2 == 0 && (a[i]-i-1)%2 == 0) ans = false;
            else ans = true;
            break;
        }
    }
    cout << (ans ? "First" : "Second") << endl;
    return 0;
}