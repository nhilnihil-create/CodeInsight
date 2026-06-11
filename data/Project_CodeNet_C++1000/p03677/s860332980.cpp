#include <iostream>
#include <vector>
using namespace std;
typedef long long ll;

int main()
{
    int n, m;
    cin >> n >> m;
    ll a[100002];
    vector<int> v[100002];
    cin >> a[0];
    a[0]--;
    v[a[0]].push_back(0);
    ll now = 0;
    ll cross = 0;
    for(int i = 1; i < n; i++){
        cin >> a[i];
        a[i]--;
        v[a[i]].push_back(i);
        if(a[i] < a[i - 1]){
            cross++;
            now += a[i] + 1;
        }
        else now += a[i] - a[i - 1];
    }
    ll ans = now;
    for(int i = 1; i < m; i++){
        for(int x : v[i - 1]){
            if(x == 0) continue;
            cross--;
            now += (a[x] - a[x - 1] + m - 1) % m;
        }
        now -= cross;
        for(int x : v[i - 1]){
            if(x == n - 1) continue;
            cross++;
        }
        ans = min(ans, now);
    }
    cout << ans << endl;
}