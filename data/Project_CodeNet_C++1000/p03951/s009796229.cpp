#pragma GCC optimize("Ofast,fast-math,unroll-loops")
 
#include <bits/stdc++.h>
 
#define int ll
//#define double long double
#define endl '\n'
#define all(C) (C).begin(), (C).end()
#define rall(C) (C).rbegin(), (C).rend()
#define mp make_pair 
#define pb emplace_back
#define dbg(x) cerr << #x << " : " << x << endl
#define PI 3.1415926535
 
using namespace std;
        
using ll = long long;
using ull = unsigned long long;
using ld = long double;
using pii = pair <int, int>;
using pld = pair <ld, ld>;

/*
const ll MAX_MEM = 3e6;
char MEM[MAX_MEM];
ll MEM_POS = 0;
void* operator new(size_t x)
{
    auto ret = MEM + MEM_POS;
    MEM_POS += x;
    assert(MEM_POS < MAX_MEM);
    return ret;
}
void operator delete(void*)
{}
*/
        
template <class T>
istream& operator>> (istream &in, vector <T> &a)
{
    for (auto &i : a)
        in >> i;
    return in;
}
        
template <class T> 
ostream& operator<< (ostream &out, vector <T> a)
{
    for (auto &i : a)
        out << i << ' ';
    return out;
}
        
template <class T, class U>
istream& operator>> (istream &in, pair <T, U> &p)
{
    in >> p.first >> p.second;
    return in;
}
        
template <class T, class U>
ostream& operator<< (ostream &out, pair <T, U> p)
{
    out << p.first << " " << p.second << " ";
    return out;
}
        
inline void Start()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);
    //freopen("lol.in", "r", stdin);
    //freopen("lol.out", "w", stdout);
}

signed main()
{
    Start();
    int n;
    string s, t;
    cin >> n >> s >> t;
    for (int len = n; len <= 2 * n; ++len)
    {
        string x(len, ' ');
        for (int i = 0; i < n; ++i)
            x[i] = s[i], x[len - i - 1] = t[n - i - 1];
        int flag = 1;
        for (int i = 0; i < n; ++i)
            flag = flag && (x[i] == s[i] && x[len - i - 1] == t[n - i - 1]);
        if (flag)
            return cout << x.size(), 0;
    }
    return 0;
}


