#include <bits/stdc++.h>
using namespace std;
template <class T>
inline bool chmax(T &a, T b)
{
    if (a < b)
    {
        a = b;
        return 1;
    }
    return 0;
}
template <class T>
inline bool chmin(T &a, T b)
{
    if (a > b)
    {
        a = b;
        return 1;
    }
    return 0;
}
typedef long long int ll;

#define ALL(v) (v).begin(), (v).end()
#define RALL(v) (v).rbegin(), (v).rend()
#define endl "\n"
const double EPS = 1e-7;
const int INF = 1 << 30;
const ll LLINF = 1LL << 60;
const double PI = acos(-1);
const int MOD = 1000000007;
const int dx[4] = {1, 0, -1, 0};
const int dy[4] = {0, 1, 0, -1};

//-------------------------------------

template <typename T>
void compression(vector<T> &v)
{
    vector<T> t = v;
    sort(ALL(t));
    t.erase(unique(ALL(t)), t.end());
    for (size_t i = 0; i < v.size(); i++)
    {
        v[i] = distance(t.begin(), lower_bound(ALL(t), v[i]));
    }
}

int main()
{
    cin.tie(0);
    ios::sync_with_stdio(false);
    int n; cin >> n;
    vector<int> a(n);
    for(int i=0;i<n;i++) cin >> a[i];
    compression<int>(a);
    int cnt = 0;
    for(int i=0;i<n;i++){
        if((a[i]+1)%2 != (i+1)%2) cnt++; 
    }
    cout << cnt / 2 << endl;
}