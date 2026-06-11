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

    int n, p;
    cin >> n;
    vector<int> x(n), ans(n * n, -1);
    vector<int> prepare, postpare, fillvec, appear(n, 0), check(n, 0);
    vector<PII> y(n);
    rep(i, n)
    {
        cin >> x[i];
        y[i] = make_pair(x[i], i + 1);
        ans[x[i] - 1] = i + 1;
    }
    sort(allpt(y));

    for (auto z : y)
    {
        rep(j, z.second - 1)
            prepare.push_back(z.second);
        rep(j, n - z.second)
            postpare.push_back(z.second);
    }

    for (auto z : prepare)
        fillvec.push_back(z);
    for (auto z : postpare)
        fillvec.push_back(z);

    p = 0;
    rep(i, n * n)
    {
        if (ans[i] == -1)
        {
            ans[i] = fillvec[p];
            p++;
        }
    }

    rep(i, n * n)
    {
        appear[ans[i] - 1]++;
        if (appear[ans[i] - 1] == ans[i])
        {
            if (i + 1 == x[ans[i] - 1])
                check[ans[i] - 1] = 1;
            else
                check[ans[i] - 1] = -1;
        }
    }

    if (accumulate(allpt(check), 0) == n)
    {
        cout << "Yes" << rt;
        show1dvec(ans);
    }
    else
        cout << "No" << rt;


    return 0;
}
