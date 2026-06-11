#include <bits/stdc++.h> 
using namespace std; 
typedef long long int ll;
typedef long double ld;
typedef unsigned long long int ull;
const long long int m=pow(10,9)+7;

int main() 
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    ll n;
    cin>>n;
    int a[n];
	for(int i=0;i<n;i++)
	    cin>>a[i];
	vector<ll>v;
	reverse(a,a+n);
	for(int i=0;i<n;i+=2)
	    v.push_back(a[i]);
    reverse(a,a+n);
    int k;
    if(n%2==0)
        k=0;
    else
        k=1;
	for(int i=k;i<n;i+=2)
	    v.push_back(a[i]);
	for(int i=0;i<n;i++)
	    cout<<v[i]<<" ";
	cout<<endl;
    return 0;
}
