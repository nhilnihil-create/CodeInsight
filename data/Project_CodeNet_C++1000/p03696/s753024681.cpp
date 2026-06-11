#include <bits/stdc++.h>
#define REP(i, n) for (int i = 0; i < (n); ++i)
template <class T>
inline bool chmin(T &a, T b)
{
    if (a > b)
    {
        a = b;
        return true;
    }
    return false;
}
template <class T>
inline bool chmax(T &a, T b)
{
    if (a < b)
    {
        a = b;
        return true;
    }
    return false;
}
using namespace std;
using ll = long long;
using P = pair<int, int>;
using Pl = pair<long long, long long>;
using veci = vector<int>;
using vecl = vector<long>;
using vecveci = vector<vector<int>>;
using vecvecl = vector<vector<long long>>;

int main()
{
    int N; cin >> N;
    vector<bool> seen(N,false);
    string S; cin >> S;
    string ans = S;
    REP(i,N) {
        if(seen[i]) continue;
        bool ok = false;
        if(S[i] == '(') {
            for(int j = i+1; j < N; j++) if(S[j] == ')' && !seen[j]) {
                ok = true;
                seen[i] = true;
                seen[j] = true;
                break;
            }
            if(!ok) ans = ans + ')';
        } else {
            for (int j = i - 1; j >= 0; j--)
                if (S[j] == '(' && !seen[j])
                {
                    ok = true;
                    seen[i] = true;
                    seen[j] = true;
                    break;
                }
            if(!ok) ans = '(' + ans;
        }
    }
    cout << ans << endl;
}