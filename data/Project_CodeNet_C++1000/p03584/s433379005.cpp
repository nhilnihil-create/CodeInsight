#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using PII = std::pair<int, int>;
using PLL = std::pair<ll, ll>;

#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define rep2(i, s, n) for (int i = (s); i < (int)(n); i++)


const int mod = 1e9 + 7;

int bittoint(vector<bool> bits)
{
    int ret, lb;
    ret = 0;
    lb = bits.size();
    rep(i, lb)
    {
        if (bits[i])
            ret += pow(2, lb - 1 - i);
    }
    return ret;
}

vector<int> bit_or_candidate(int k)
{
    int lk, x;
    vector<int> ret;
    vector<bool> bits, bits2;
    ret.push_back(k);

    x = k;
    lk = 0;
    while (x > 0)
    {
        bits.push_back(x % 2);
        lk++;
        x /= 2;
    }

    reverse(bits.begin(), bits.end());
    bits2.resize(lk);

    rep(i, lk)
    {
        rep(j, i)
        {
            if (j >= 0)
                bits2[j] = bits[j];
        }

        if (bits[i])
        {
            bits2[i] = 0;
            rep2(j, i + 1, lk)
                bits2[j] = 1;
        }
        else
        {
            rep2(j, i, lk)
                bits2[j] = bits[j];
        }
        ret.push_back(bittoint(bits2));
    }
    return ret;
}

ll orsum(vector<int> num, vector<int> value, int k)
{
    ll ret = 0;
    int n = num.size();
    rep(i, n)
    {
        if ((num[i] | k) == k)
            ret += value[i]; 
    }
    return ret;
}

int main()
{

#ifdef DEBUG
    cout << "DEBUG MODE" << endl;
    ifstream in("input.txt"); //for debug
    cin.rdbuf(in.rdbuf());    //for debug
#endif

    int n, k, a, b;
    cin >> n >> k;
    ll ans = 0;
    vector<int> num, value, candidate;
    rep(i, n)
    {
        cin >> a >> b;
        num.push_back(a);
        value.push_back(b);
    }

    candidate = bit_or_candidate(k);

    for (auto z : candidate)
    {
        ans = max(ans, orsum(num, value, z));
    }
    cout << ans << endl;
    return 0;
}
