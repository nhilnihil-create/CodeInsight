#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;

int main(int argc, char **argv)
{
	vector <ll> arr(3);
  for(ll i=0;i<3;i++) cin>>arr[i];
  ll count_5=0;
  ll count_7=0;
  for(ll i=0;i<3;i++){
    if (arr[i]==5) count_5++;
    if (arr[i]==7) count_7++;
  }
  if (count_5==2&&count_7==1) cout<<"YES"<<"\n";
  else cout<<"NO"<<"\n";
	return 0;
}
