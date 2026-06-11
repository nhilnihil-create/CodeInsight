#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;

int main(int argc, char **argv)
{
	ll n,l;
  cin>>n>>l;
  vector <string> arr(n);
  for(ll i=0;i<n;i++) cin>>arr[i];
  sort(arr.begin(),arr.end());
  for(ll i=0;i<n;i++) cout<<arr[i];
	return 0;
}
