#include<bits/stdc++.h>
#define speed_up ios_base::sync_with_stdio(false); cin.tie(NULL)
#define ll long long
#define ara(A,N) sort(A,A+N)
#define rev(A,N) sort(A,A+N,greater<long long>())
using namespace std;
int main()
{
  speed_up;
  ll n, m, i, j, k, x;
  ll M = 1e9 + 7;

    cin >> n;
    map<ll, ll> a;
    for(k = 2; k <= n; ++k)
    {
        ll cnt = 0;
        ll num = k;
        while(num % 2 == 0) {
            ++cnt;
            num /= 2;
        }
        if(cnt) a[2] += cnt;
        for(i = 3; i <= num; i += 2) {
            if(num % i == 0) {
                cnt = 0;
                while(num % i == 0) {
                    ++cnt;
                    num /= i;
                }
                a[i] += cnt;
            }
        }
        if(num > 1) a[num]++;
    }

    ll tot = 1;
    for(auto t : a)
    {
        tot *= (t.second + 1);
        tot %= M;
    }
    cout << tot << endl;




return 0;
}

