#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define rep(i, srt, end) for (long long i = (srt); i < (long long)(end); i++)

int main(){
    ll a, b, c;
    cin >> a >> b >> c;
    ll ans1 = (a % 2) * b * c;
    ll ans2 = (b % 2) * a * c;
    ll ans3 = (c % 2) * a * b;
    cout << min({ans1, ans2, ans3}) << endl;
    return 0;
}