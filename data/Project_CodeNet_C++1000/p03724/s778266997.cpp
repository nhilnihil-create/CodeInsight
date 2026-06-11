#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using PII = std::pair<int, int>;
using PLL = std::pair<ll, ll>;

#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define rep2(i, s, n) for (int i = (s); i < (int)(n); i++)
#define allpt(v) (v).begin(), (v).end()


const int mod = 1e9 + 7;
const string wsp = " ";
const string tb = "\t";
const string rt = "\n";

template <typename T>
void show1dvec(vector<T> v)
{
    int n = v.size() - 1;
    rep(i, n) cout << v[i] << wsp;
    cout << v[n] << rt;
    return;
}



int main()
{

#ifdef DEBUG
    cout << "DEBUG MODE" << endl;
    ifstream in("input.txt"); //for debug
    cin.rdbuf(in.rdbuf());    //for debug
#endif

    int n, m, a, b, ev;
    cin >> n >> m;
    vector<int> deg(n, 0);

    rep(i, m)
    {
        cin >> a >> b;
        a--, b--;
        deg[a]++, deg[b]++;
    }

    ev = 0;
    rep(i, n) if (deg[i]  % 2 == 0) ev++;
    
    cout << ( (ev == n) ? "YES" : "NO") << rt;

    return 0;
}
