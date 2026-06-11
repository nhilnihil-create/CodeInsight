#include<bits//stdc++.h>
using namespace std;
typedef long long ll;
#define rep(i,n) for(int i = 0; i < n;i++)
string s, t; ll n, m, p, q, ans = 0, sum = 0, num = 0;
int main() {
    cin >> n; vector<int> a(n);
    rep(i, n) {
        cin >> a[i];
    }
    rep(i, n) {
        sum += a[i];      // 1項目＋
        if (i % 2 == 0 && sum <= 0) {
            num += 1 - sum;
            sum = 1;
        }
        else if (i % 2 == 1 && sum >= 0) {
            num += sum + 1;
            sum = -1;
        }
    }sum = 0;
    rep(i, n) {  // first -
        sum += a[i]; 
        if (i % 2 == 0 && sum >= 0) {
             ans += sum + 1;
             sum = -1;
        }
        else if (i % 2 == 1 && sum <= 0) {
             ans += 1 - sum;
             sum = 1;
        }
    }
    cout << min(ans, num) << endl;
}