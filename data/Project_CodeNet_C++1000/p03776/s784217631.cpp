#include<bits/stdc++.h>
using namespace std;using ll=long long;using vi=vector<int>;using vvi=vector<vi>;using vl=vector<ll>;using vvl=vector<vl>;using P=pair<int,int>;using PL=pair<ll,ll>;using vp=vector<P>;using vpl=vector<PL>;
template<typename T>constexpr auto inf=numeric_limits<T>::max()/2;constexpr int INF=inf<int>,MOD=1000000007;constexpr ll LINF=inf<ll>;
#define _ol3(_1,_2,_3,name,...)name
#define _rep(i,n)_repi(i,0,n)
#define _repi(i,a,b)for(int i=a,i##_l=(b);i<i##_l;++i)
#define REP(...)_ol3(__VA_ARGS__,_repi,_rep,)(__VA_ARGS__)
#define REPR(i,n)for(int i=n-1;i>=0;--i)
#define REPA(i,v)REP(i,v.size())
#define all(v)(v).begin(),(v).end()
#define bit(n)(1ll<<(n))
#define uniq(v)sort(all(v));v.erase(unique(all(v)),v.end())
#define F first
#define S second
#define endl '\n'
#define cho(n,a,b)cout<<((n)?a:b)<<endl
void YES(int n){cho(n,"YES","NO");}void Yes(int n){cho(n,"Yes","No");}void Poss(int n){cho(n,"Possible","Impossible");}
void _print(ostream&){}template<class T,class...U>void _print(ostream&s,T&&t,U&&...u){s<<t<<(sizeof...(u)?' ':'\n');_print(s,u...);}
template<class...T>void print(T&&...t){_print(cout,t...);}
#ifndef LOCAL
struct osd{template<class T>osd&operator<<(const T&t){return*this;}};osd cer_;
#define dprint(...)
#define cerr cer_
#else
template<class...T>void dprint(T&&...t){_print(cerr,t...);}
#endif
template<class T>void chmax(T&a,const T&b){if(a<b)a=b;}template<class T>void chmin(T&a,const T&b){if(a>b)a=b;}
template<class T>ostream&operator<<(ostream&o,const vector<T>&v){for(auto&&i:v)o<<i<<' ';return o;}
template<class T>istream&operator>>(istream&i,vector<T>&v){for(T&j:v)i>>j;return i;}
template<class T,class U>ostream&operator<<(ostream&o,const pair<T,U>&p){return o<<p.F<<' '<<p.S;}
template<class T,class U>istream&operator>>(istream&i,pair<T,U>&p){return i>>p.F>>p.S;}
template<class T>ostream&operator<<(ostream&o,const set<T>&v){for(auto&&i:v)o<<i<<' ';return o;}
template<class T>ostream&operator<<(ostream&o,const multiset<T>&v){for(auto&&i:v)o<<i<<' ';return o;}
template<class T>vector<T>&operator<<(vector<T>&v,const T&t){v.push_back(t);return v;}
template<class T>set<T>&operator<<(set<T>&v,const T&t){v.insert(t);return v;}
template<class T>multiset<T>&operator<<(multiset<T>&v,const T&t){v.insert(t);return v;}

bool fr_gr(PL a, PL b){
    return a.F*b.S > b.F*a.S;
}
bool fr_eq(PL a, PL b){
    return a.F*b.S == b.F*a.S;
}

int main(){
    cin.tie(0);ios::sync_with_stdio(0);cout<<fixed<<setprecision(10);
    ll n,a,b;
    cin>>n>>a>>b;
    vvl cc(n+1);
    cc[0].resize(1,1);
    REP(i,1,n+1){
        cc[i].resize(i+1);
        REP(j,i+1){
            if(j==i)cc[i][j]=cc[i-1][j-1];
            else if(j==0)cc[i][j]=cc[i-1][j];
            else cc[i][j]=cc[i-1][j-1]+cc[i-1][j];
        }
    }
    vl v(n);
    map<ll,int> m;
    cin>>v;
    sort(all(v), greater<ll>());
    REP(i,n)m[v[i]]++;
    PL av(0,1);
    ll cur=0;
    ll s=0;
    ll last_cnt=0;
    REP(i,a){
        s+=v[i];
        if(i && v[i]==v[i-1])last_cnt++;
        else last_cnt=1;
    }
    REP(i,a,b+1){
        dprint(i,s);
        dprint("l",m[v[i-1]], last_cnt);
        if(fr_gr(PL(s,i), av)){
            dprint("gr");
            av=PL(s,i);
            //cur=comb(m[v[i-1]], last_cnt);
            cur=cc[m[v[i-1]]][last_cnt];
        }else if(fr_eq(PL(s,i), av)){
            //cur+=comb(m[v[i-1]], last_cnt);
            cur+=cc[m[v[i-1]]][last_cnt];
        }
        if(v[i]==v[i-1])last_cnt++;
        else last_cnt=1;

        if(i!=n)s+=v[i];
    }
    cout<<(double)av.F/av.S<<endl;
    cout<<cur<<endl;
    dprint(cur==1125899906842623ll);
    return 0;
}
