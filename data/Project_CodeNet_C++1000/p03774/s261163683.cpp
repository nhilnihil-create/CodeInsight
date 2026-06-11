  /*  HARD WORK FOREVER PAYS  */
#include<bits/stdc++.h>
#define pb push_back
#define mk make_pair
#define f first
#define s second
#define turbo(){	\
	ios_base::sync_with_stdio(false); \
	cin.tie(NULL); \
}
using namespace std;
typedef long long ll;
typedef pair<int,int> PII; 
int main() 
{ 
	turbo();
	int y,x,j,i,n,m;
	cin>>n>>m;
	vector<PII> v,v2;
	for(i=0;i<n;i++){	
		cin>>x>>y;
		v.pb({x,y});
	}	
	for(j=0;j<m;j++){
		cin>>x>>y;
		v2.pb({x,y});
	}
	for(i=0;i<n;i++){
		int mi=INT_MAX,ans=0;
		for(j=0;j<m;j++){
			if(min(mi,abs(v[i].f-v2[j].f)+abs(v[i].s-v2[j].s))<mi){
				ans=j+1;
				mi=min(mi,abs(v[i].f-v2[j].f)+abs(v[i].s-v2[j].s));
			}
		}
		cout<<ans<<"\n";
	}
	return 0; 
} 