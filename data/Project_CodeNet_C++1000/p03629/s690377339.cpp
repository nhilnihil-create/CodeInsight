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

const int n_max = 200006;

signed main(){
    string s;
    cin >> s;
    int n = s.size();
    int nagasa[n + 1];
    nagasa[n] = 0;
    bool vis[26];
    REP(i,26) vis[i] = false;
    int cnt = 0;
    REPR(i,n-1){
        if(vis[s[i] - 'a'] == false){
            cnt ++;
            vis[s[i] - 'a'] = true;
            if(cnt == 26){
                nagasa[i] = nagasa[i+1] + 1;
                cnt = 0;
                REP(i,26) vis[i] = false;
            }
            else{
                nagasa[i] = nagasa[i+1];
            }
        }
        else{
            nagasa[i] = nagasa[i+1];
        }
    }

    int tugi[n_max][26];
    int ids[26];
    REP(i,26) ids[i] = 0;
    REP(i,n){
        FOR(j,ids[s[i] - 'a'],i+1){
            tugi[j][s[i] - 'a'] = i;
        }
        ids[s[i] - 'a'] = i + 1;
    }
    REP(i,26){
        FOR(j,ids[i],n) tugi[j][i] = n;
    }








    int idx = 0;
    while(1){
        REP(i,26){
            if(tugi[idx][i] == n){
                cout << moji[i] <<endl;
                return 0;
            }
            if( nagasa[tugi[idx][i] + 1] == nagasa[idx] - 1){
                cout << moji[i];
                idx = tugi[idx][i] +  1;
                break;
            }
        }
    }
}