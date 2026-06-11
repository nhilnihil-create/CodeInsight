#include <bits/stdc++.h>
using namespace std;
#define fi first
#define se second
#define mp make_pair
#define pb push_back
#define inf 1000000000
#define mod 1000000007
#define li 100005
#define FOR for(int i=1;i<=n;i++)
typedef pair< int,int > PII;
typedef long long int lo;
lo n,m,cev,b;
string s;
vector<int> v;
int main(){
	scanf("%lld",&n);
	lo bas=1;
	lo son=n;
	while(bas<=son){
		lo mid=(bas+son)/2;
		if(mid*(mid+1)/2>=n){
			son=mid-1;
		}
		else bas=mid+1;
	}
	printf("%lld",bas);
	return 0;
}
