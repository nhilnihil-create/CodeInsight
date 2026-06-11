#include <bits/stdc++.h>
using namespace std;
#define REP(i, n) for(int i = 0;i < n;i++)
#define REPR(i, n) for(int i = n;i >= 0;i--)
#define FOR(i, m, n) for(int i = m;i < n;i++)
#define fi first
#define se second
#define mp make_pair
#define itrfor(itr,A) for(auto itr = A.begin(); itr !=A.end();itr++)
template <class T> using reversed_priority_queue = priority_queue<T, vector<T>, greater<T> >;
typedef long long llong;
char moji[26]={'a','b','c','d','e','f','g','h','i','j','k','l','m','n','o','p','q','r','s','t','u','v','w','x','y','z'};
char moji2[26]={'A','B','C','D','E','F','G','H','I','J','K','L','M','N','O','P','Q','R','S','T','U','V','W','X','Y','Z'};
char moji3[10]={'0','1','2','3','4','5','6','7','8','9'};
#define Sort(a) sort(a.begin(),a.end());
#define Reverse(a) reverse(a.begin(),a.end());
#define print(a) cout << a << endl;
#define MOD llong(1e9+7)
#define MAX int(2 * 1e5 +5)
#define debug(x)  cout << #x << " = " << (x) << endl;
#define pi acos(-1.0)
#define int llong
#define INF llong(1e17)
template<class T> bool chmax(T &a,  T b) {if(a<b){a=b; return 1;} return 0;}
template<class T> bool chmin(T &a,  T b) {if(a>b){a=b; return 1;} return 0;}
bool Add(int &a,int b){a = (a + b) % MOD;}
void myprint(int* A,int A_num){
   REP(i,A_num) cout << A[i] << " ";
   cout << endl;
}

signed main(){
    string s,t;
    cin >> s >> t;
    int s_size = s.size();
    int t_size = t.size();
    int rui_s[s_size + 1];
    int rui_t[t_size + 1];
    rui_s[0] = 0;
    rui_t[0] = 0;
    REP(i,s_size) rui_s[i+1] = rui_s[i] + int(s[i] == 'A');
    REP(i,t_size) rui_t[i+1] = rui_t[i] + int(t[i] == 'A');

    int q;
    cin >> q;
    REP(i,q){
        int a,b,c,d;
        cin >> a >> b >> c >> d;
        a--;
        b--;
        c--;
        d--;
        int anum = rui_s[b+1] - rui_s[a];
        int snum = anum - (b+1- a - anum);
        snum += 3 * s_size;
        anum = rui_t[d+1] - rui_t[c];
        int tnum = anum - (d+1 - c - anum);
        tnum += 3 * t_size;
        if( (snum % 3) == (tnum % 3) ){
            cout << "YES" << endl;
        }
        else{
            cout << "NO" << endl;
        }
    }

}