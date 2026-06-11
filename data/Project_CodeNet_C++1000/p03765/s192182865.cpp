#include<bits/stdc++.h>

using namespace std;
using ll = long long;


int main()
{
    string s, t; cin >> s >> t;
    int n = s.size(), m = t.size();
    int q; cin >> q;

    vector<int> sa(n + 1), ta(m + 1);
    for(int i = 0; i < n; i++)sa[i + 1] = sa[i] + (s[i] == 'A');
    for(int i = 0; i < m; i++)ta[i + 1] = ta[i] + (t[i] == 'A');

    while(q--) {
        int ls, rs, lt, rt; cin >> ls >> rs >> lt >> rt;
        ls--, lt--;
        int nums = rs - ls;
        nums = sa[rs] - sa[ls] + (nums - (sa[rs] - sa[ls])) * 2;
        //nums個のaをなんとかする
        int numt = rt - lt;
        //cerr << nums << endl;
        nums += (numt - (ta[rt] - ta[lt]));
        //cerr << nums << endl;
        nums -= ta[rt] - ta[lt];
        //cerr << nums << endl;
        cout << (nums % 3 ? "NO" : "YES") << endl;
    }
}