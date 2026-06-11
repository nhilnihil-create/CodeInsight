#include<iostream>
#include<algorithm>
#define maxn 100005
using namespace std;
typedef long long ll;
ll a[maxn] = { 0 };
int main() {
    ll n, i;
    cin >> n;
    for (int i = 1; i <= n; ++i) {
        cin >> a[i];
    }
    ll sum1 = 0;  ll sum2 = 0;
    ll ans1 = 0; ll ans2 = 0;
    for (int i = 1;i <= n; ++i) {
        sum1 += a[i];
        if (i % 2 == 0 && sum1 >= 0) {
            ans1 += sum1 + 1;
            sum1 = -1;
        }
        else if (i % 2 != 0 && sum1 <= 0) {
            ans1 += abs(sum1) + 1;
            sum1 = 1;
        }
    }
    for (int i = 1; i <= n; ++i) {
        sum2 += a[i];
        if (i % 2 == 0 && sum2 <= 0) {
            ans2 += abs(sum2) + 1;
            sum2 = 1;
        }
        else if (i % 2 != 0 && sum2 >= 0) {
            ans2 += abs(sum2) + 1;
            sum2 = -1;
        }
    }
    cout << min(ans1, ans2) << endl;
    return 0;
}