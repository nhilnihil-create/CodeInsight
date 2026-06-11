#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using pii = pair<int, int>;
template <class T>
using v = vector<T>;
template <class T>
using vv = v<v<T>>;
#define ALL(c) (c).begin(), (c).end()

int main()
{
    int N;
    cin >> N;
    v<int> a(N);

    int tgt = 0;
    for (int i = 0; i < N; i++)
    {
        cin >> a[i];
        tgt += a[i];
    }

    tgt = round((double)tgt/N);

    ll ans = 0;
    for (int i = 0; i < N; i++)
        ans += (int)floor(pow(tgt-a[i],2));
    
    cout << ans << endl;

    return 0;
}