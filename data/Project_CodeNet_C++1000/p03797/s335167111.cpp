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
	ll s,n,m,ans=0;
	cin>>n>>m;
	ans=min(n*2,m-m%2)/2;
	m-=ans*2;
	ans+=(m/4);
	cout<<ans<<"\n";
    return 0; 
} 