#include<bits/stdc++.h>
#define rep(i,a,b) for(int i=a;i<b;i++)
#define rrep(i,a,b) for(int i=a;i>=b;i--)
#define fore(i,a) for(auto &i:a)
#define all(x) (x).begin(),(x).end()
//#pragma GCC optimize ("-O3")
using namespace std; void _main(); int main() { cin.tie(0); ios::sync_with_stdio(false); _main(); }
typedef long long ll; const int inf = INT_MAX / 2; const ll infl = 1LL << 60;
template<class T>bool chmax(T &a, const T &b) { if (a<b) { a = b; return 1; } return 0; }
template<class T>bool chmin(T &a, const T &b) { if (b<a) { a = b; return 1; } return 0; }
//------------------------------------------------------------------------------
template<typename T, int N, T F(const T& a, const T& b)>
struct SegTree
{
public:
    SegTree()
    {
        dat = vector<T>(N * 2 - 1, 0);
    }

    void update(int i, T x)
    {
        i += N - 1;
        dat[i] = x;
        while (i > 0)
        {
            i = (i - 1) / 2;
            dat[i] = F(dat[i * 2 + 1], dat[i * 2 + 2]);
        }
    }

    T query(int a, int b, int k = 0, int l = 0, int r = N)
    {
        if (r <= a || b <= l) return 0;
        if (a <= l && r <= b) return dat[k];
        else
        {
            T vl = query(a, b, k * 2 + 1, l, (l + r) / 2);
            T vr = query(a, b, k * 2 + 2, (l + r) / 2, r);
            return F(vl, vr);
        }
    }

    vector<T> dat;
};

/*------------------------------------------------------------------------------
　　　　　　　　　　　 ∧＿∧  
　　　　　 ∧＿∧ 　（´<_｀ ）　 Welcome to My Coding Space!
　　　　 （ ´_ゝ`）　/　 ⌒i     
　　　　／　　　＼　 　  |　|     
　　　 /　　 /￣￣￣￣/　　|  
　 ＿_(__ﾆつ/　    ＿/ .| .|＿＿＿＿  
　 　　　＼/＿＿＿＿/　（u　⊃  
------------------------------------------------------------------------------*/











//------------------------------------------------------------------------------
ll N, W;
ll w[105], v[105];
//------------------------------------------------------------------------------
void _main()
{
    cin >> N >> W;
    vector<ll> vs[4];
    rep(i, 0, N)
    {
        cin >> w[i] >> v[i];
        vs[w[i] - w[0]].push_back(v[i]);
    }
    rep(i, 0, 4) sort(vs[i].rbegin(), vs[i].rend());
    rep(i, 0, 4) rep(j, 0, vs[i].size()) if (j > 0) vs[i][j] += vs[i][j - 1];
/*    rep(i, 0, 4)
    {
        rep(j, 0, vs[i].size())
        {
            cout << vs[i][j] << ", ";
        }
        cout << endl;
    }*/
    ll ans = 0;
    rep(nw0, 0, vs[0].size() + 1)
    {
        rep(nw1, 0, vs[1].size() + 1)
        {
            rep(nw2, 0, vs[2].size() + 1)
            {
                rep(nw3, 0, vs[3].size() + 1)
                {
                    if (w[0] * nw0 + (w[0] + 1) * nw1 + (w[0] + 2) * nw2 + (w[0] + 3) * nw3 <= W)
                    {
                        ll tmp = 0;
                        if (nw0 > 0) tmp += vs[0][nw0 - 1];
                        if (nw1 > 0) tmp += vs[1][nw1 - 1];
                        if (nw2 > 0) tmp += vs[2][nw2 - 1];
                        if (nw3 > 0) tmp += vs[3][nw3 - 1];
                        chmax(ans, tmp);
//                        cout << tmp << endl;
                    }
                }
            }
        }
    }
    cout << ans << endl;
}
