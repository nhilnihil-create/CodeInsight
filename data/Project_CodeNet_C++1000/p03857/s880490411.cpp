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
void _print(ostream&s){}template<class T,class...U>void _print(ostream&s,T&&t,U&&...u){s<<t<<(sizeof...(u)?' ':'\n');_print(s,u...);}
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

class UnionFind{
private:
	vi data;
public:
	UnionFind(int size):data(size,-1){}
	bool unite(int x,int y){
		x=root(x);y=root(y);
		if(x!=y){
			if(data[y]<data[x])swap(x,y);
			data[x]+=data[y];data[y]=x;
		}
		return x!=y;
	}
	bool find(int x,int y){
		return root(x)==root(y);
	}
	int root(int x){
		return data[x]<0?x:data[x]=root(data[x]);
	}
	int size(int x){
		return -data[root(x)];
	}
};

int main(){
    cin.tie(0);ios::sync_with_stdio(0);
    int n,k,l;
    cin>>n>>k>>l;
    UnionFind a(n),b(n);
    REP(i,k){
        int p,q;
        cin>>p>>q;
        a.unite(p-1,q-1);
    }
    REP(i,l){
        int r,s;
        cin>>r>>s;
        b.unite(r-1, s-1);
    }
    map<P, int> p;
    REP(i,n){
        p[P(a.root(i), b.root(i))]++;
    }
    REP(i,n){
        cout<<p[P(a.root(i), b.root(i))]<<' ';
    }
    cout<<endl;
    return 0;
}
