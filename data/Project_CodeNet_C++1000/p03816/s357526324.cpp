#include<bits/stdc++.h>
using namespace std;

int a[100000] = {0};
int main()
{
  	int n;
  	cin>>n;
  	int c[n];
  	for(int i = 0; i < n; i++)
    {
      	cin>>c[i];
  		a[c[i]]++;
    }
  	long long int res = 0;
  	for(int i = 0; i < 100000; i++)
      	if(a[i] > 0)
          	res++;
  	if(res % 2 == 0)
      	cout<<res-1<<"\n";
  	else 
      	cout<<res<<"\n";
	return 0;
}
