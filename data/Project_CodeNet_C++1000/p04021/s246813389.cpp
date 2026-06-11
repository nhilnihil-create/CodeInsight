#include <bits/stdc++.h>
using namespace std;
#define finish(x) return cout << x << endl, 0
#define ll long long

int n;
vector <int> a;
map <int, int> mp;

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> n;
    a.resize(n);
    for(auto &i : a){
        cin >> i;
        mp[i];
    }
    int x = 0;
    for(auto &i : mp) i.second = x++;
    for(auto &i : a) i = mp[i];
    int ans = 0;
    for(int i = 0 ; i < n ; i += 2){
        ans += a[i] % 2;
    }
    cout << ans << endl;
}
