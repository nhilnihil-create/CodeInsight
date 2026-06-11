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
	ll n ,mod=1e9+7,i,ans=1;
	cin>>n;
	for(i=1;i<=n;i++){
		ans*=i;
		ans%=mod;
	}
	cout<<ans<<"\n";
    return 0; 
} 