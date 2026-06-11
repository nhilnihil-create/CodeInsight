#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
const LL MOD = 1000000007;
#define lcm(x, y) ((x) * (y) / __gcd((x), (y)))
#define pb push_back
#define all(c) (c).begin(), (c).end()
#define debug(x) cout << #x << " : " << x << endl
#define part cout << "----------------------------------\n";
#include <iostream>

#define fastinput                     \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL);                    \
    cout.tie(NULL);

int main()
{
    fastinput;
    LL n, i, j, k, t, temp, M;
    cin >> n >> M;
   // vector<LL> v(M), pairs(M);
    map<LL, LL> freq, freqmod;
    LL cnt = 0;
    for (i = 0; i < n; i++)
    {
        cin >> j;
        freq[j]++;
    }

    for (auto x : freq)
    {
        LL num = x.first;
        LL f = x.second;
        if (f & 1)
        {
          //  cout<<"increasing due to "<<num<<endl;
            freqmod[num % M]++;
            freq[num]--;
        }
    }

    for (auto &x : freqmod)
    {
        LL num = x.first;
        LL f = freqmod[num];
        if (f == 0)
        {
            continue;
        }
        else
        {

            LL complement = (M - num)%M;
            LL a = min(f, freqmod[complement]);
            cnt += a;
           // cout << "num is " << num << endl;
           // debug(a);
            freqmod[num] -= a;
            freqmod[complement] -= a;
        }
    }

    for (auto x : freqmod)
    {
        LL num = x.first;
        LL f = x.second;
        if (f == 0)
        {
            freqmod.erase(num);
        }
    }
   // debug(cnt);
   // cout<<"invetifate\n";
    for (auto x : freq)
    {
        LL num = x.first;
        LL f = x.second;
       // debug(num);
        //debug(f);
       // part;
        LL reqd = freqmod[(M-num % M)%M];
        LL add = min(reqd, f);
        cnt += add;
        freq[num] -= add;
        freqmod[(M-num % M)%M] -= add;
        cnt += (freq[num] / 2);
    }
    //debug(cnt);
    cout<<cnt<<endl;

    return 0;
}
