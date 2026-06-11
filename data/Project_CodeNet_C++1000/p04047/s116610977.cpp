#include<iostream>
#include<algorithm>
using namespace std;
#define int long long int
int32_t main()
{
  int n;
  cin>>n;
  int arr[2*n],j;
  for(j=0;j<2*n;j++)
    cin>>arr[j];
  sort(arr,arr+2*n);
  int answer=0;
  for(j=0;j<2*n;j+=2)
    answer+=arr[j];
  cout<<answer<<endl;
}
