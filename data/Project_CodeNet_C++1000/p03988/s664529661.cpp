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
//#define PI 3.141592653589
 
using namespace std;
        
using ll = long long;
using ull = unsigned long long;
using ld = long double;
using pii = pair <int, int>;
using pld = pair <ld, ld>;

/*
const ll MAX_MEM = 4e8;
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

void bad()
{
    cout << "Impossible";
    exit(0);
}
void good()
{
    cout << "Possible";
    exit(0);
}

signed main()
{
    Start();
    // There should be test:
    // 7
    // 6 6 3 4 5 5 5
    int n;
    cin >> n;
    vector <int> a(n);
    cin >> a;
    sort(all(a));
    if (a[n - 1] != a[n - 2])
        bad();
    if (a[0] != (a[n - 1] + 1) / 2)
        bad();
    if (a[n - 1] % 2 == 0)
    {
        if (a[0] == a[1])
            bad();
    }
    else
    {
        if (n > 2 && a[0] == a[1] && a[1] == a[2])
            bad();
    }
    set <int> s;
    for (auto &i : a)
        s.emplace(i);
    for (int i = a[0]; i < a[n - 1]; ++i)
        if (!s.count(i))
            bad();
    good();
    return 0;
}

