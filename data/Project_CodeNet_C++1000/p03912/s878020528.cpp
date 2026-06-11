#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

#define EPS (1e-7)
#define INF (1e9)
#define PI (acos(-1))
//const ll mod = 1000000007;

int main() {
    //cout.precision(10);
    int n, m;
    cin >> n >> m;
    map<int, int> mp;
    for(int i = 0; i <= 100000; i++){
        mp[i] = 0;
    }
    for(int i = 1; i <= n; i++){
        int in;
        cin >> in;
        mp[in]++;
    }
    int odds[100500];
    int evens[100500];
    for(int i = 0; i <= 100000; i++){
        odds[i] = 0;
        evens[i] = 0;
    }
    for(int i = 1; i <= 100000; i++){
        int number = i % m;
        evens[number] += (mp[i] / 2) * 2;
        if(mp[i] % 2 == 1){
            odds[number]++;
        }
    }
    int ans = 0;
    //for(int i = 1; i <= 1; i++){
    for(int i = 1; i * 2 < m; i++){
        int number = min(odds[i], odds[m - i]);
        ans += number;
        odds[i] -= number;
        odds[m - i] -= number;
        //cout << ans << endl;
        number = min(odds[i], evens[m - i]);
        ans += number;
        //cout << ans << endl;
        odds[i] -= number;
        evens[m - i] -= number;
        number = min(evens[i], odds[m - i]);
        ans += number;
        //cout << ans << endl;
        evens[i] -= number;
        odds[m - i] -= number;
        ans += evens[i] / 2;
        ans += evens[m - i] / 2;
        //cout << i << " " << ans << endl;
    }
    ans += odds[0] / 2;
    evens[0] += (odds[0] % 2);
    ans += evens[0] / 2;
    if(m % 2 == 0){
        int check = m / 2;
        ans += odds[check] / 2;
        evens[check] += (evens[check] % 2);
        ans += evens[check] / 2;
    }
    cout << ans << endl;
    return 0;
}
