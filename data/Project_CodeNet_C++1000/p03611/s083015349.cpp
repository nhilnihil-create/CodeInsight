#include<bits/stdc++.h>
#define speed_up ios_base::sync_with_stdio(false); cin.tie(NULL)
#define ll long long
#define ara(A,N) sort(A,A+N)
#define rev(A,N) sort(A,A+N,greater<long long>())
using namespace std;
int main()
{
  speed_up;
  int n, i;
  cin>>n;
  int num[100005] = {};
  int a[n];
  for(i = 0; i<n; i++)
  {
      cin>>a[i];
      num[a[i]]++;
      if(a[i]-1>=0) num[a[i]-1]++;
      num[a[i]+1]++;
  }
  cout<<*max_element(num, num + 100005)<<endl;
  //YAY.




return 0;
}

