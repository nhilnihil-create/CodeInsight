#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using P = pair<ll, ll>;
int main()
{
    string s, t;
    cin >> s >> t;
    int ssize = s.size();
    int tsize = t.size();
    vector<int> ss(ssize+1);
    vector<int> ts(tsize+1);
    for(int i = 0; i < ssize; i++)
    {
        if(s[i] == 'A')
        {
            ss[i+1] = ss[i] + 1;
        }
        else
        {
            ss[i+1] = ss[i] + 2;
        }
    }
    for(int i = 0; i < tsize; i++)
    {
        if(t[i] == 'A')
        {
            ts[i+1] = ts[i] + 1;
        }
        else
        {
            ts[i+1] = ts[i] + 2;
        }
    }
    int q;
    cin >> q;
    while(q)
    {
        int a, b, c, d;
        cin >> a >> b >> c >> d;
        int s3 = (ss[b] - ss[a-1]) % 3;
        int t3 = (ts[d] - ts[c-1]) % 3;
        if(s3 == t3) cout << "YES" << endl;
        else cout << "NO" << endl;
        q--;
    }
}
