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
    int n, x;
    cin >> n >> x;
    if (x == 1 || x == 2 * n - 1)
        return cout << "No", 0;
    cout << "Yes\n";
    if (n == 2)
        return cout << "1\n2\n3", 0;
    if (x != 2 * n - 2)
    {
    vector <int> used(2 * n), a(2 * n - 1);
    a[n - 1] = x - 1, a[n - 2] = x, a[n - 3] = x + 1, a[n] = x + 2;
    used[x - 1] = used[x] = used[x + 1] = used[x + 2] = 1;
    for (int i = 0, j = 1; i < 2 * n - 1; ++i)
    {
        if (a[i])
            continue;
        while (used[j])
            ++j;
        a[i] = j, used[j] = 1;
    }
    for (auto &i : a)
        cout << i << endl;
    }
    else
    {
    vector <int> used(2 * n), a(2 * n - 1);
    a[n - 1] = x + 1, a[n - 2] = x, a[n - 3] = x - 1, a[n] = x - 2;
    used[x + 1] = used[x] = used[x - 1] = used[x - 2] = 1;
    for (int i = 0, j = 1; i < 2 * n - 1; ++i)
    {
        if (a[i])
            continue;
        while (used[j])
            ++j;
        a[i] = j, used[j] = 1;
    }
    for (auto &i : a)
        cout << i << endl;
    }
    return 0;
}


