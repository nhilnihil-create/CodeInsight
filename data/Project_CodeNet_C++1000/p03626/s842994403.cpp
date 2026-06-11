#include <bits/stdc++.h>
#define itn int
#define REP(i, n) for (int i = 0; i < (n); i++)
#define IREP(i, n) for (int i = n - 1; i >= 0; i--)
#define FOR(i, k, n) for (int i = (k); i < (n); i++)
#define REPEACH(itr, k) for (auto &&itr : k)
#define MOD 1000000007

using namespace std;
typedef long long ll;

const ll INF = 1LL<<60;
template<class T> inline bool chmin(T &a, T b){if (a > b){a = b;return true;}return false;}
template<class T> inline bool chmax(T &a, T b){if (a < b){a = b;return true;}return false;}

int main()
{
    int n;
    cin >> n;
    string s1,s2;
    cin >> s1 >> s2;
    ll ans=1;
    vector<bool> s1_b(n,false);
    vector<bool> s2_b(n,false);
    REP(i,n){
        if(s1[i]==s2[i]){
            if(i==0){
                ans*=3;
            }
            else if(s1[i-1]==s2[i-1]){
                ans*=2;
            }
            else{
                ans*=1;
            }
            s1_b[i]=true;
            s2_b[i]=true;
        }
        else{
            if (i == 0)
            {
                ans *= 6;
            }
            else if (s1[i - 1] == s2[i - 1])
            {
                ans *= 2;
            }
            else
            {
                ans *= 3;
            }
            s1_b[i] = true;
            s2_b[i] = true;
            i++;
            s1_b[i]=true;
            s2_b[i]=true;
        }
        ans%=MOD;
    }
    cout << ans << endl;
}