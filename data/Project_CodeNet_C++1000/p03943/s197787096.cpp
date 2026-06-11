#include <bits/stdc++.h>
#define nl ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
#define ll long long
#define all(v) (v).begin(), (v).end()
#define allr(v) (v).rbegin(), (v).rend()
#define pi acos(-1)

using namespace std;

int main() {
    nl // 

    vector<int> v(3);

    for(auto &x : v) cin >> x;
    sort(all(v));

    cout << (v[2] != v[0] + v[1] ? "No" : "Yes");


    return 0;
}