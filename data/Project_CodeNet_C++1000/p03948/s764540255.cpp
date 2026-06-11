#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const ll mod = 1000000007;

#include <bits/stdc++.h>
using namespace std;

string to_string(string s)
{
    return '"' + s + '"';
}

string to_string(const char *s)
{
    return to_string((string)s);
}

string to_string(bool b)
{
    return (b ? "true" : "false");
}

template <typename A, typename B>
string to_string(pair<A, B> p)
{
    return "(" + to_string(p.first) + ", " + to_string(p.second) + ")";
}

template <typename A>
string to_string(A v)
{
    bool first = true;
    string res = "{";
    for (const auto &x : v)
    {
        if (!first)
        {
            res += ", ";
        }
        first = false;
        res += to_string(x);
    }
    res += "}";
    return res;
}

void debug_out() { cerr << endl; }

template <typename Head, typename... Tail>
void debug_out(Head H, Tail... T)
{
    cerr << " " << to_string(H);
    debug_out(T...);
}

int N, T, ans, minv = mod, maxg = 0;

int main()
{
    cin >> N >> T;
    vector<int> A(N);
    for (int i = 0; i < N; i++)
    {
        cin >> A[i];
        if (A[i] <= minv)//min
            minv = A[i];
        if (maxg < A[i] - minv)
        {
            maxg = A[i] - minv;
            ans = 1;
        }
        else if (maxg == A[i] - minv)
            ans++;
    }
    cout << ans << endl;
}