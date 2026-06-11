#include <bits/stdc++.h>
#define rep(i, a, n) for(int i = a; i < n; i++)
using namespace std;
using ll = long long;
using P = pair<int, int>;

int main()
{
    string o, e;
    cin >> o >> e;
    string ans;
    int cnt = 0;
    while(cnt < o.size() + e.size()){
        ans += o[cnt/2];
        cnt++;
        if(cnt >= o.size() + e.size()) break;
        ans += e[cnt/2];
        cnt++;
    }
    cout << ans << endl;
    return 0;
}
