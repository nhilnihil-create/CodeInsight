#include <bits/stdc++.h>
#define _overload3(_1,_2,_3,name,...) name
#define _rep(i,n) repi(i,0,n)
#define repi(i,a,b) for(int i=int(a);i<int(b);i++)
#define rep(...) _overload3(__VA_ARGS__,repi,_rep,)(__VA_ARGS__)
#define rrep(i,n) for (int i=(n-1);i >= 0;i--)
#define all(v) v.begin(),v.end()
#define sz(v) (int)((v).size())
#define MAX(v) *max_element(all(v))
#define MIN(v) *min_element(all(v))
using namespace std; using ll = long long; using P = pair<int,int>;
using vl = vector<ll>; using vvl = vector<vl>;
inline void IN(void){return;}
template <typename First, typename... Rest>
void IN(First& first, Rest&... rest){cin >> first;IN(rest...);return;}
template<class T>bool chmax(T &a, const T &b) {if(a<b){a=b; return 1;} return 0;}
template<class T>bool chmin(T &a, const T &b) {if(b<a){a=b; return 1;} return 0;}
const ll INF = 1LL << 60;
const int dx[8] = {1,0,-1,0,1,1,-1,-1}; const int dy[8] = {0,1,0,-1,1,1,-1,-1};

int main(){
    cin.tie(0); ios::sync_with_stdio(false);
    int a,b,c,d,e,f;
    IN(a,b,c,d,e,f);
    int ans1=0,ans2=0;
    for(int x=0;100*a*x <= f;x++){
        for(int y=0;100*b*y <= f-100*a*x;y++){
            if(x==0&&y==0) continue;
            for(int z=0;c*z<=f-100*a*x-100*b*y;z++){
                for(int w=0;d*w<=f-100*a*x-100*b*y-c*z;w++){
                    int wat = 100*a*x+100*b*y;
                    int sug = c*z+d*w;
                    if(wat*e<sug*100) break;
                    if(ans1==0){
                        ans1 = wat+sug;
                        ans2 = sug;
                    }
                    if(sug*ans1>(wat+sug)*ans2){
                        ans1 = wat+sug;
                        ans2 = sug;
                    }
                }
            }
        }
    }
    printf("%d %d\n",ans1,ans2);
}