#include <bits/stdc++.h>
/* S.size() s.substr(l,r=s.size()-l) -> l文字目からr文字分
__gcd()　lower_bound(a+l,a+r,x)-a でindex
// 配列  -> min/max({}) 
// vector-> *min_element(a+l,a+r)  *忘れず lとrで[l,r) 
//reverse(a+l,a+r)   配列aの[l,r)を逆順に strはreverse(all(s))
//sort(a+l,a+r,greater <int>()) 配列aの[l,r)昇順sort,大きい順はgreater<type>()
//vectorならall(v)
clock()/CLOCKS_PER_SEC で秒数
vector v.push_back(x),v.pop_back()
q.push(x),front()で先頭を返す,pop()で削除, size(),empty()
<deque>(push/pop)_(front/back)/fornt/back/insert/
priority_queue 宣言は priority_queue< Type, vector<Type>, greater<Type>> Q1; 
// pq.push(x),top()で参照 pop()で削除   greaterで最小 lessで最大がtopに*/
using namespace std;
#define all(v) (v).begin(), (v).end()
#define rep(i,n) for(int (i)=0;(i)<(n);(i)++)
#define print(i) std::cout << (i) << '\n'
#define rrep(i,n) for(int (i)=(n)-1;(i)!=-1;(i)--)
#define vep(i,v) for(auto (i)=v.begin();(i)<(v.end());(i)++)
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return true; } return false; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return true; } return false; }
inline long long ceildiv(long long a, long long  b) { return (a+b-1)/b; }
typedef pair<long long,long long> P;
typedef pair<int,int> PI;
using Graph = std::vector<std::vector<int> >;
const long long inf = 10e17;
const long long mod = 1000000007;
//int |x|<=2*10**9     long |x|<= 9*10**18
//printf(".(小数点以下の桁数)lf(double時、float ならf)")
#define ll long long
struct edge{ll from,to,cost;};
edge es[2200];
ll d[2200];
int n,m;

ll path(int s){
    rep(i,n+1){d[i]=-inf;}
    d[s]=0;
    int cnt=0;
    
    ll pre=-inf;
    while (true){
        bool update=false;
        rep(i,m){
            edge e=es[i];
            if (d[e.from]!=-inf &&d[e.to]<d[e.from]+e.cost){
                d[e.to]=d[e.from]+e.cost;update=true;
            }
        } if(!update)return d[n];
        cnt++;
        if (d[n]>pre)pre=d[n];
        if(cnt>=n+1){
         rep(i,m){
            edge e=es[i];
            if (d[e.from]!=-inf &&d[e.to]<d[e.from]+e.cost){
                d[e.to]=d[e.from]+e.cost;
            }
        } if (pre<d[n])return -inf-10;else{return pre;}
        }
    }
} 
int main(){
cin>>n>>m;
rep(i,m){ll a,b,c;cin>>a>>b>>c;edge x;x.from=a;x.to=b;x.cost=c;es[i]=x;}
ll ans=path(1);
if (ans==-inf-10){print("inf");}else{print(ans);}
}
