#include <bits/stdc++.h>
#define ll long long
#define pb push_back
#define ep emplace_back
#define st first
#define sc second

using namespace std;

const ll mod = 998244353;
const int e = 1e6 + 69;
const int base = 311;

// dung igt thay cho gt luc tinh giai thua
// 3
// cach tao hoan vi tu n so : n*(n+1)/2;

ll s[e];
int a, b, n;


int main()
{
    ll n;
    string s;
    cin >> n;
    cin >> s;
    string thanhdink;
    ll cur = 0;
    for(int i=0; i<n; i++)
    {
        if(s[i] == ')')
        {
            if(cur - 1 < 0)
            {
                thanhdink += '(';
            }
            cur = max(cur - 1, 0LL);
        }
        else
        {
            cur ++;
        }
    }
    s = thanhdink + s;
    for(int i=1; i<=cur; i++)
    {
        s += ')';
    }
    cout << s;
}
