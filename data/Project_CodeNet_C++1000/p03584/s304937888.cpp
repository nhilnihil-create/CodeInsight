#include <iostream>
#define __ ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
using namespace std;

long long a[100050],b[100050];

int main()
{
	long long i,j,n,k,ans=0,tmp,test;
	cin >> n >> k;
	for(i=0;i<n;i++)
		cin >> a[i] >> b[i],ans+=((a[i]|k)==k) ? b[i] : 0;
	//cout << ans << "\n";
	for(i=1;i<30;i++) 
	{
		if(!(k>>i&1)) continue;
		tmp=0,test=(k>>i<<i)-1;
		for(j=0;j<n;j++) tmp+=((a[j]|test)==test) ? b[j] : 0;
		//cout << i << " " << test << " " << tmp << "\n";
		ans=max(ans,tmp); 
	}
	cout << ans << "\n";
}