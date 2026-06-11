#include <bits/stdc++.h>
#define PI 3.1415926535897
using namespace std;
typedef long long ll;
const int INF = 1000000000;
const ll LINF = 1000000000000000000; //1e18
const double EPS = 1e-10;

int main(void)
{
    int N;
    cin >> N;

    vector<int> a(N);
    ll sum = 0;
    for (int i = 0; i < N; i++)
    {
        cin >> a[i];
        sum += a[i];
    }

    ll average = sum / N;
    ll x1 = average - 1;
    ll x2 = average;
    ll x3 = average + 1;
    ll ans1 = 0; // average - 1
    ll ans2 = 0; // average
    ll ans3 = 0; // average + 1
    for (int i = 0; i < N; i++)
    {
        ans1 += pow((a[i] - x1), 2);
        ans2 += pow((a[i] - x2), 2);
        ans3 += pow((a[i] - x3), 2);
    }

    ll mn = min({ans1, ans2, ans3});
    cout << mn << endl;
    return (0);
}