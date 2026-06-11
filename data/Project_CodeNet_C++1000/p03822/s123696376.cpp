#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using VI = vector<int>;
using VL = vector<ll>;
using PII = std::pair<int, int>;
using PLL = std::pair<ll, ll>;

#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define repr(i, n) for (int i = (int)(n)-1; i >= 0; i--)
#define rep2(i, s, n) for (int i = (s); i < (int)(n); i++)
#define allpt(v) (v).begin(), (v).end()
#define allpt_c(v) (v).cbegin(), (v).cend()
#define allpt_r(v) (v).rbegin(), (v).rend()


const int mod = 1e9 + 7;
const string wsp = " ";
const string tb = "\t";
const string rt = "\n";

template <typename T>
void show1dvec(const vector<T> &v)
{
    if (v.size() == 0)
        return;
    int n = v.size() - 1;
    rep(i, n) cout << v[i] << wsp;
    cout << v[n] << rt;
    return;
}

template <typename T>
void show2dvec(const vector<vector<T>> &v)
{
    int n = v.size();
    rep(i, n) show1dvec(v[i]);
}

template <typename T, typename S>
void show1dpair(const vector<pair<T, S>> &v)
{
    int n = v.size();
    rep(i, n) cout << v[i].first << wsp << v[i].second << rt;
    return;
}

template <typename T, typename S>
void pairzip(const vector<pair<T, S>> &v, vector<T> &t, vector<T> &s)
{
    int n = v.size();
    rep(i, n)
    {
        t.push_back(v[i].first);
        s.push_back(v[i].second);
    }
    return;
}

template <typename T>
void maxvec(vector<T> &v)
{
    T s = v[0];
    int n = v.size();
    rep(i, n - 1)
    {
        if (s > v[i + 1])
        {
            v[i + 1] = s;
        }
        s = v[i + 1];
    }
}

template <typename T, typename S>
bool myfind(T t, S s)
{
    return find(t.cbegin(), t.cend(), s) != t.cend();
}

vector<int> make_kmp_table(string t)
{
    int lt = t.length();
    VI kmptable(lt, 0);
    kmptable[0] = -1;

    return kmptable;
}

int getdepth(VI v, const VI &depth)
{
    if (v.size() == 0)
        return 0;

    int ret = 0;
    rep(i, v.size()) v[i] = depth[v[i]];
    sort(allpt_r(v));
    rep(i, v.size()) v[i] += i;

    ret = *max_element(allpt_c(v)) + 1;
    return ret;
}

int main()
{

#ifdef DEBUG
    cout << "DEBUG MODE" << endl;
    ifstream in("input.txt"); //for debug
    cin.rdbuf(in.rdbuf());    //for debug
#endif

    // int n;
    // string s, t;
    // cin >> n >> s;
    // VL dp(n + 1, 0ll);
    // vector<set<int>> callspell(n);
    // dp[0] = 1;
    // rep(i, n)
    // {
    //     cin >> t;
    // }

    // rep(i, n)
    // {
    //     for (int z : callspell[i])
    //     {
    //         dp[i + z - 1] += dp[i - 1];
    //         dp[i + z - 1] %= mod;
    //     }
    // }

    // cout << dp[n] << rt;

    int n, x;
    cin >> n;
    VI depth(n, 0), search, new_search, unsearch_losers(n, 0), winner(n);
    vector<VI> new_depth(n);

    winner[0] = -1;
    rep(i, n - 1)
    {
        cin >> x;
        x--;
        unsearch_losers[x]++;
        winner[i + 1] = x;
    }

    rep(i, n) if (unsearch_losers[i] == 0) search.push_back(i);
    

    while (!search.empty())
    {
        for (int i : search)
        {
            if (i != 0)
            {
                new_depth[winner[i]].push_back(i);
                unsearch_losers[winner[i]]--;
                if (unsearch_losers[winner[i]] == 0)
                {
                    new_search.push_back(winner[i]);
                    depth[winner[i]] = getdepth(new_depth[winner[i]], depth);
                }
            }
        }
        search.clear();
        search = new_search;
        new_search.clear();
        
    }
    cout << getdepth(new_depth[0], depth) << rt;

    return 0;
}
