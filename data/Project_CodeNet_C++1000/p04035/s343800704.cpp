#include <bits/stdc++.h>
using namespace std;

int main() {
	int i;
	int n, l;
	cin>>n>>l;
	int a[n];
	for(i=0;i<n;i++)
    cin>>a[i];

	int m = a[0]+a[1];
	int posi = 0;
	for(i=0;i+1<n;i++)
	{
		if(m<a[i]+a[i+1])
		{
			m = a[i]+a[i+1];
			posi = i;
		}
	}

	if (m<l)
	{
	    cout<<"Impossible"<<endl;
	    return 0;
    }

	cout<<"Possible"<<endl;
	for(i=0;i<posi;i++)
    {
		cout<<i+1<<endl;
	}
	for(i=n-2;i>posi;i--)
    {
		cout<<i+1<<endl;
	}
	cout<<posi+1<<endl;
}
