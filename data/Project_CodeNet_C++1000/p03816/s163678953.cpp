#include <bits/stdc++.h>
using namespace std;
#define dhoom ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);  
typedef long long ll;
typedef long double ld;
const ll inf = 1e18;
const int nax = 2e6 + 7;
const ll mod = 1e9 + 7;
//ll tree[4 * nax];
//9uS-22RSwk7gQqh
int count(ll x){
	int cnt = 0;
	while(x != 0){
		cnt++;
		x /= 10;
	}
	return cnt;
}
int cnt[1000000];
int main()
{
	int n;
	cin>>n;
	for(int i=0;i<n;i++)
	{
		int x;
		cin>>x;
		cnt[x]++;
	}	
	for(int i=1;i<=100000;i++)
	{
		if(cnt[i]>1)
		{
			n-=cnt[i]-1;
		}
	}
	if(n%2==0)
		n--;
	cout<<n<<endl;
} 

