#include <bits/stdc++.h>
#define nl ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
#define ll long long
#define all(v) (v).begin(), (v).end()
#define allr(v) (v).rbegin(), (v).rend()

using namespace std;

int main() {
    nl // youtu.be/QosiU0JR_h8  
    ll x, t;
    cin >> x >> t;
    cout << (x >= t ? x-t : 0);
    return 0;
}