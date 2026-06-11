#include <bits/stdc++.h>
#define ll long long int
#define mod_ceil(a, b) (a % b) ? a / b + 1 : a / b
#define mod 1000000007
using namespace std;

bool prime[1010];
vector<int> prime_list;

void init()
{
    memset(prime, true, 1001 * sizeof(bool));
    prime[1] = false;
    for (int i = 2; i < 1001; i++)
    {
        if (prime[i])
        {
            prime_list.push_back(i);
            for (int j = i * 2; j < 1001; j += i)
            {
                prime[j] = false;
            }
        }
    }
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    init();

    ll n;
    cin >> n;
    map<int, int> M;
    for (int i = 2; i <= n; i++)
    {
        ll tmp = i;
        for (auto j : prime_list)
        {
            if (j > tmp)
                break;

            while (tmp % j == 0)
            {
                tmp /= j;
                M[j]++;
            }
        }
    }
    ll ans = 1;
    for (auto i = M.begin(); i != M.end(); i++)
    {
        ans = (ans * (i->second + 1)) % mod;
    }
    cout << ans << endl;
}