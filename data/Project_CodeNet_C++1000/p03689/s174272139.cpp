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
#define INFL 0x3f3f3f3f3f3f3f3fLL
#define SIZE 100005

using namespace std;
typedef vector<int> vi; typedef pair<int, int> pii; typedef vector<pair<int, int> > vpii; typedef long long ll;
typedef pair<int,ll> pill; typedef pair<ll,int> plli; 
typedef pair<double, int> pdi;
template<typename T, typename U> inline void amin(T &x, U y) { if(y < x) x = y; }
template<typename T, typename U> inline void amax(T &x, U y) { if(x < y) x = y; }
typedef complex<double> P;
long long int MOD = 1000000007;
int H,W,h,w;
int main()
{
	cin>>H>>W>>h>>w;
	if(H%h==0&&W%w==0){
		cout<<"No"<<endl;
	}else{
		cout<<"Yes"<<endl;
		int Bsum,Wsum;
		Bsum=((H-1)/h+1)*((W-1)/w+1);
		Wsum=H*W-Bsum;
		//cout<<Bsum<<" "<<Wsum<<endl;
		int x=1;
		while(Bsum*((h*w-1)*x-1)<=Wsum*x)x++;
		for(int i=0;i<H;i++){
			for(int j=0;j<W;j++){
				if(i%h==0&&j%w==0)cout<<(h*w-1)*x-1;
				else cout<<-x;
				if(j!=W-1)cout<<" ";
			}
			cout<<endl;
		}
	}
	
}