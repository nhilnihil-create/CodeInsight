#include<bits/stdc++.h>

using namespace std;

#define LL long long
#define DD double
#define Pb push_back
#define Bp pop_back
#define Pf push_front
#define Fp pop_front
#define Ub upper_bound
#define Lb lower_bound
#define In insert
#define All(x) x.begin(), x.end()
#define mem(a, b) memset(a, b, sizeof(a))
#define fast ios_base::sync_with_stdio(0);cin.tie(0)
#define X first
#define Y second
#define mx1 10
#define mx2 110
#define mx3 1010
#define mx4 10010
#define mx5 100010
#define mx6 1000010

typedef vector<LL> Vl;
typedef vector<DD> Vd;
typedef vector<bool> Vb;
typedef vector<Vl> VVl;
typedef pair<LL, LL> Pll;
typedef pair<DD, DD> Pdd;
typedef vector<Pll> Vpl;
typedef vector<Pdd> Vpd;
typedef queue<LL> Ql;
typedef stack<LL> Sl;
typedef deque<LL> Dl;

LL _set(LL N, LL pos) {return N = N | (1 << pos);}
LL _reset(LL N, LL pos) {return N = N & ~(1 << pos);}
bool _check(LL N, LL pos) {return (bool)(N & (1 << pos));}
bool _upper(char a) {return a >= 'A' && a <= 'Z';}
bool _lower(char a) {return a >= 'a' && a <= 'z';}
bool _digit(char a) {return a >= '0' && a <= '9';}

LL dx[] = {1, -1, 0, 0, -1, -1, 1, 1};
LL dy[] = {0, 0, 1, -1, -1, 1, -1, 1};

///**************************DONE****************************///

int main()
{
    int n;
    cin >> n;

    map<int, int> mp;
    for(int i = 0; i < n; i++){
        int a;
        cin >> a;

        mp[a]++;
    }

    vector<pair<LL, int>> v;
    for(auto i: mp)
        v.Pb({i.X, i.Y});

    int f = -1, L = v.size();
    LL ans = 0;

    for(int i = 0; i < L; i++){
        if(v[i].Y > 3)
            ans = max(ans, v[i].X * v[i].X), f = i;
        else if(f >= 0 && v[i].Y > 1)
            ans = max(ans, v[i].X * v[f].X), f = i;
        else if(v[i].Y > 1)
            f = i;
    }

    cout << ans << '\n';
    return 0;
}
