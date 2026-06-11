#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
using namespace std;
#define PI  3.14159265358979323846
#define lp(i,n) for(int i = 0; i <n;i++)
#define rlp(i,n) for(int i = int(n);i >= 0;i--)
#define range1(i,a,b,c) for(int i = int(a);i <= int(b);i+=int(c))
#define range(i,a,b) for(int i = int(a);i <= int(b);i++)
#define all(x) (x).begin(),(x).end()
#define pb push_back
#define MP make_pair
#define fr first
#define sc second
#define sz(v) ((int)((v).size()))
#define sfi1(v) scanf("%d",&v)
#define sfi2(v1, v2) scanf("%d %d",&v1,&v2)
#define sfi3(v1, v2, v3) scanf("%d %d %d",&v1,&v2,&v3)
#define sfll1(v) scanf("%I64d",&v);
#define sfll2(v1, v2) scanf("%I64d %I64d",&v1,&v2)
#define sfll3(v1, v2, v3) scanf("%I64d %I64d %I64d",&v1,&v2,&v3)
typedef long long ll;
typedef unsigned long long ull;
typedef vector<int> vi;
typedef vector<pair<int, int> > vii;
typedef pair<int, int> pii;
template<class T> using ordered_set=tree<T,
null_type,
less<T>,
rb_tree_tag,
tree_order_statistics_node_update>;
const ll MOD = 1e9 + 7;
const int OO = (int)1e6;
const int N = (int)1e7;
int dx[] = {0,0,-1,1};
int dy[] = {1,-1,0,0};
void init(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
}
//w = 1 , s = 0
// idx , (w|s)
string s;
bool _solve(vii &v,int n){
    while(sz(v)<n){
        int pre = v[sz(v)-2].sc;
        int idx = v[sz(v)-1].fr;
        int cur = v[sz(v)-1].sc;
        if(s[idx]=='x'){
            if(cur==1){
                v.pb({(idx+1)%n,pre});
            }else{
                v.pb({(idx+1)%n,1-pre});
            }
        }else{
            if(cur==1){
                v.pb({(idx+1)%n,1-pre});
            }else{
                v.pb({(idx+1)%n,pre});
            }
        }
    }
    string ans(n,2);
     lp(idx,n){
        ans[v[idx].fr]=v[idx].sc?'W':'S';
     }
     for(int i=0;i<n;i++){
         char pre = ans[(i-1+n)%n];
         char next = ans[(i+1)%n];
         int idx =i;
         if(ans[idx]=='S'){
             if(s[idx]=='x'){
                 if(pre==next){
                     return false;
                 }
             }else{
                 if(pre!=next)
                    return false;
             }
         }else{
              if(s[idx]=='x'){
                 if(pre!=next){
                     return false;
                 }
             }else{
                 if(pre==next)
                    return false;
             }
         }
     }
     return true;
}
void _run(){
    int n;
    scanf("%d",&n);
   
    cin>>s;
    int l = sz(s)-1;
    int r = 1;
    int c = 0;
    lp(i,2){
        lp(j,2){
            lp(k,2){
                vii v;
                v.pb({l,i});
                v.pb({c,j});
                v.pb({r,k});
                if(_solve(v,n)){
                    string ans(sz(v),1);
                    lp(idx,n){
                        ans[v[idx].fr]=v[idx].sc?'W':'S';
                    }
                    printf("%s",ans.c_str());
                    return ;
                }
            }
        }
    }
    puts("-1");
}
int main() {
	#   ifdef LOCAL_PROJECT
        freopen("in.txt", "r", stdin);
    #   endif
    int t=1;
    // scanf("%d",&t);
    while(t--)_run();
    
    return 0;
}