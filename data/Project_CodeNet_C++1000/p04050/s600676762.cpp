#include <string>
#include <vector>
#include <algorithm>
#include <numeric>
#include <set>
#include <map>
#include <queue>
#include <iostream>
#include <sstream>
#include <cstdio>
#include <cmath>
#include <ctime>
#include <cstring>
#include <cctype>
#include <cassert>
#include <limits>
#include <functional>
#include <iomanip>
#include <complex>
#define rep(i,n) for(int (i)=0;(i)<(int)(n);++(i))
#define rer(i,l,u) for(int (i)=(int)(l);(i)<=(int)(u);++(i))
#define reu(i,l,u) for(int (i)=(int)(l);(i)<(int)(u);++(i))
#if defined(_MSC_VER) || __cplusplus > 199711L
#define aut(r,v) auto r = (v)
#else
#define aut(r,v) __typeof(v) r = (v)
#endif
#define each(it,o) for(aut(it, (o).begin()); it != (o).end(); ++ it)
#define all(o) (o).begin(), (o).end()
#define pb(x) push_back(x)
#define mp(x,y) make_pair((x),(y))
#define mset(m,v) memset(m,v,sizeof(m))
#define INF 0x3f3f3f3f
#define INFL 0x3f3f3f3f3f3f3f3fLL
using namespace std;
typedef vector<int> vi; typedef pair<int, int> pii; typedef vector<pair<int, int> > vpii; typedef long long ll;
typedef pair<pii,int> ppiii ;
template<typename T, typename U> inline void amin(T &x, U y) { if(y < x) x = y; }
template<typename T, typename U> inline void amax(T &x, U y) { if(x < y) x = y; }
typedef complex<double> P;
int n,m;
int main(){
	int x;
	cin>>n>>m;
	vi b,c;
	int cnt=0;
	for(int i=0;i<m;i++){
		cin>>x;
		if(x%2==1)b.pb(x);
		else c.pb(x);
	}
	if(b.size()>=3){
		cout<<"Impossible"<<endl;
	}else{
		vi ans,check;
		if(b.size()>0)check.pb(b[0]);
		for(int i=0;i<c.size();i++)check.pb(c[i]);
		for(int i=1;i<b.size();i++)check.pb(b[i]);
		for(int i=0;i<check.size();i++){
			int hoge=check[i];
			if(i==0){
				hoge--;
			}
			if(i==check.size()-1){
				hoge++;
			}
			if(hoge!=0)ans.pb(hoge);
		}
		if(check.size()==1){
			ans.clear();
			ans.pb(1);
			if(check[0]!=1)ans.pb(check[0]-1);
		}
		for(int i=0;i<check.size();i++){
			cout<<check[i];
			if(i!=check.size()-1)cout<<" ";
			else cout<<endl;
		}
		cout<<ans.size()<<endl;
		for(int i=0;i<ans.size();i++){
			cout<<ans[i];
			if(i!=ans.size()-1)cout<<" ";
			else cout<<endl;
		}
	}
}