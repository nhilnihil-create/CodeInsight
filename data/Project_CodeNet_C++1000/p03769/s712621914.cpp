#include "bits/stdc++.h"
#define MAXN 100009
#define INF 1000000007
#define mp(x,y) make_pair(x,y)
#define all(v) v.begin(),v.end()
#define pb(x) push_back(x)
#define wr cout<<"----------------"<<endl;
#define ppb() pop_back()
#define tr(ii,c) for(typeof((c).begin()) ii=(c).begin();ii!=(c).end();ii++)
#define ff first
#define ss second
#define my_little_dodge 46
using namespace std;

typedef long long ll;
typedef pair<int,int> PII;
template<class T>bool umin(T& a,T b){if(a>b){a=b;return 1;}return 0;}
template<class T>bool umax(T& a,T b){if(a<b){a=b;return 1;}return 0;}
int main(){
	ll n;
	scanf("%lld",&n);n++;
	vector<int>v;
	while(n>=2){
		if(n%2==0)
			v.pb(1),n/=2;
		else
			v.pb(2),n--;
	}reverse(all(v));
	deque<int>d;
	for(int i=0;i<int(v.size());i++){
		if(v[i]==1)
			d.pb(i+1);
		else
			d.push_front(i+1);
	}
	printf("%d\n",2*int(d.size()));
	for(int i=0;i<int(d.size());i++)
		printf("%d ",d[i]);
	for(int i=0;i<int(d.size());i++)
		printf("%d ",i+1);
	puts("");	
	return 0;
}
