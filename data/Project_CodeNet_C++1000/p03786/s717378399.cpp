#include <bits/stdc++.h>
using namespace std;
#define all(n) begin(n), end(n)
const long long INF = numeric_limits<long long>::max();
typedef long long ll;
typedef vector<int> vint;
typedef vector<vector<int>> vvint;
typedef vector<ll> vll;
typedef vector<vector<ll>> vvll;
typedef unsigned long long ull;
template <class T>
bool chmax(T &a, const T &b)
{
    if (a < b)
    {
        a = b;
        return 1;
    }
    return 0;
}
template <class T>
bool chmin(T &a, const T &b)
{
    if (b < a)
    {
        a = b;
        return 1;
    }
    return 0;
}
template <typename T>
vector<T> make_v(size_t a) { return vector<T>(a); }

template <typename T, typename... Ts>
auto make_v(size_t a, Ts... ts)
{
    return vector<decltype(make_v<T>(ts...))>(a, make_v<T>(ts...));
}
template <typename T, typename V>
typename enable_if<is_class<T>::value == 0>::type
fill_v(T &t, const V &v) { t = v; }

template <typename T, typename V>
typename enable_if<is_class<T>::value != 0>::type
fill_v(T &t, const V &v)
{
    for (auto &e : t)
        fill_v(e, v);
}
int main()
{
    int N;
    cin>>N;
    vll A(N);
    for (size_t i = 0; i < N; i++)
    {
        cin>>A[i];
    }
    sort(all(A));
    vll acc(N);
    partial_sum(all(A),acc.begin());
    int ans=0;
    ll Min = A.back();
    for (int i = N-1; i >=0; i--)
    {
        if(i==N-1)
        ans++;
        else if(2*acc[i] >= Min)
        {
            chmin(Min,A[i]);
            ans++;
        }
        
    }
    cout<<ans<<endl;    
    return 0;
}