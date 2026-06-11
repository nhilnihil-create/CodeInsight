//#define _GLIBCXX_DEBUG
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;
typedef vector<long long> vll;
typedef vector<bool> vb;
#define pb push_back
#define fi first
#define se second
#define in insert
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
#define speed ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
const int mod = 1e9 + 7;
void solve(){
    int n;
    cin >> n;
    int cnt0 = 0, cnt1 = 0, cnt2 = 0;
    for (int i = 0; i < n; ++i) {
        int x;
        cin >> x;
        if (x % 4 == 0) cnt2++;
        else if (x % 2 == 0) cnt1++;
        else cnt0++;
    }
    if (cnt2 >= cnt0) cout << "Yes";
    else if (cnt0 - cnt2 == 1 && cnt1 == 0) cout << "Yes";
    else cout << "No";
}
int main(){
    speed;
    int t = 1;
    //cin >> t;
    for (int i = 1; i <= t; ++i) {
        solve();
    }
}