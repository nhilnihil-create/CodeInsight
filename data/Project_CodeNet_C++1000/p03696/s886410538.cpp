#include<algorithm>
#include<bitset>
#include<cmath>
#include<complex>
#include<deque>
#include<functional>
#include<iomanip>
#include<iostream>
#include<iterator>
#include<map>
#include<numeric>
#include<queue>
#include<set>
#include<stack>
#include<string>
#include<unordered_map>
#include<unordered_set>
#include<utility>
#include<vector>
#include<chrono>
using namespace std;
#define rep(i,n) for(int i=0; i<(n); i++)
#define repr(i, n, x) for(int i=(n); i>(x); i--)
#define FOR(i,x,n) for(int i=x; i<(n); i++)
#define vint(a,n) vint a(n); rep(i, n) cin >> a[i];
#define vll(a,n) vll a(n); rep(i, n) cin >> a[i];
#define ALL(n) begin(n),end(n)
#define RALL(n) rbegin(n),rend(n)
#define MOD (1000000007)
#define INF (2e9)
#define INFL (2e18)

typedef long long ll;
typedef unsigned int ui;
typedef unsigned long long ull;
using vint=vector<int>;
using vll=vector<ll>;
using vbool=vector<bool>;
template<class T>using arr=vector<vector<T>>;
template<class T>int popcount(T &a){int c=0; rep(i, 8*(int)sizeof(a)){if((a>>i)&1) c++;} return c;}
template<class T>void pr(T x){cout << x << endl;}
template<class T>void prvec(vector<T>& a){rep(i, a.size()-1){cout << a[i] << " ";} pr(a[a.size()-1]);}
template<class T>void prarr(arr<T>& a){rep(i, a.size()) if(a[i].empty()) pr(""); else prvec(a[i]);}
template<class T>bool chmax(T &a, const T &b) { if (a<b) { a=b; return 1; } return 0; }
template<class T>bool chmin(T &a, const T &b) { if (b<a) { a=b; return 1; } return 0; }

int main()
{
    int n; cin >> n;
    string s; cin >> s;
    string ans;
    string back;

    int right=0, left=0;
    int cnt = 0;
    rep(i, n){
        if(s[i]=='(') break;
        cnt++;
    }
    left = cnt;
    rep(i, cnt) ans.push_back('(');

    cnt = 0;
    repr(i, n-1, -1){
        if(s[i]==')') break;
        cnt++;
    }
    right=cnt;
    rep(i, cnt) back.push_back(')');
    ans = ans + s + back;
    // pr(ans);

    cnt = 0;
    string t;
    rep(i, ans.size()){
        if(ans[i]==')') cnt++;
        else cnt--;
        if(cnt>0) {
            t.push_back('(');
            cnt = 0;
        }
    }
    ans = t + ans;
    // pr(ans);

    string u;
    cnt = 0;
    repr(i, ans.size()-1, -1){
        if(ans[i]=='(') cnt++;
        else cnt--;
        if(cnt>0){
            u.push_back(')');
            cnt = 0;
        }
    }
    ans += u;
    pr(ans);
    return 0;}