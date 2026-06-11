#include<bits/stdc++.h>
using namespace std;

int main()
{
	int ar[3];
	int i;
	for(i=0;i<3;i++){
		cin>>ar[i];
	}
	sort(ar,ar+3);

	int ans=ar[0]+ar[1];
	cout<<ans<<endl;
}