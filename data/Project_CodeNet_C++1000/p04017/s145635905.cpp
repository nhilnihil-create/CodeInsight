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


const int n_max = 100005;

signed main(){
    int n;
    cin >> n;
    int X[n];
    REP(i,n) cin >> X[i];
    int L;
    cin >> L;

    int tugi[n_max][25];
    REP(i,n_max) REP(j,25) tugi[i][j] = n;
    REP(i,n-1){
        int l = i + 1;
        int r = n;

        while(l + 1 < r){
            int mid = (l + r) / 2;
            if(X[mid] - X[i]<= L) l = mid;
            else r = mid;
        }
        tugi[i][1] = l;
    }
    REP(j,23){
        REP(i,n){
            if(tugi[i][j+1] == n) tugi[i][j+2] =n;
            tugi[i][j+2] = tugi[tugi[i][j+1]][j+1];
        }
    }



    int beki[30];
    beki[1] = 1;
    FOR(i,1,29) beki[i + 1] = beki[i] * 2;

    int q;
    cin >> q;
    REP(i,q){
        int a,b;
        cin >> a >> b;
        a--;
        b--;
        if(a == b){
            cout << 0 << endl;
            continue;
        }
        if(a > b) swap(a,b);
        int id = 24;
        int now = a;
        int ans = 0;
        while(now != b){
            if(tugi[now][id] <= b){
                now = tugi[now][id];
                ans += beki[id];
            }
            id--;
            if(id == 0) break;
        }
        if(now != b) ans ++;
        cout << ans << endl;
    }
}