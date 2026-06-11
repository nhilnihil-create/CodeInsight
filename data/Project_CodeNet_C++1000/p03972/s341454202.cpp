#include "iostream"
#include "algorithm"
#include "string"
#include "vector"
#include "cmath"
#include "bitset"
#include "queue"
#include "functional"
#include "map"
#include "unordered_map"
#include "set"
#include "stack"
 
#define lp(n) for (int i = 0; i < n; i++)
#define LP(n,i) for (int i = 0; i < n; i++)
#define mod 1000000007
#define sp ' '
#define intmax 2147483647
#define llmax 9223372036854775807
#define nyan "(=^･ω･^=)"
typedef long long ll;
using namespace std;

int w,h,p[100000],q[100000],l,r;
ll ans,ps[100000];

int main(){
	cin>>w>>h;
	ans=0;
	lp(w){
		cin>>p[i];
		ans+=p[i];
	}
	lp(h){
		cin>>q[i];
		ans+=q[i];
	}
	sort(p,p+w);
	ps[0]=p[0];
	lp(w-1)
		ps[i+1]=ps[i]+p[i+1];
	lp(h){
		l=-1;
		r=w;
		while(l+1!=r){
			if(p[(l+r)/2]<q[i])
				l=(l+r)/2;
			else r=(l+r)/2;
		}
		ans+=(l!=-1?ps[l]:0)+ll(q[i])*(w-r);
	}
	cout<<ans<<endl;
	return 0;
}
