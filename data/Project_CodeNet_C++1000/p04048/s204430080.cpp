#pragma GCC optimize("Ofast,fast-math,unroll-loops")
  
#include <bits/stdc++.h>
//#include <ext/pb_ds/assoc_container.hpp>
//#include <ext/pb_ds/tree_policy.hpp>
  
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
//using namespace __gnu_pbds;
         
using ll = long long;
using ull = unsigned long long;
using ld = long double;
using pii = pair <int, int>;
using pll = pair <ll, ll>;
using pld = pair <ld, ld>;
 
/*
const ll MAX_MEM = 5e8;
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
    //freopen("circlecover.in", "r", stdin);
    //freopen("circlecover.out", "w", stdout);
}
 
signed main()
{
    Start();
    int ans = 0;
    int a, b;
    cin >> a >> b;
    ans += a;
    a = a - b;
    if (a < b)
        swap(a, b);
    while (b != 0)
    {
        int cur = a / b;
        ans += cur * (b + b);
        a %= b;
        swap(a, b);
    }
    cout << ans - a;
    return 0;
}

