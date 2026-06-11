#include<iostream>
#include<algorithm>
using namespace std;
int N_MAX = 100000;
int main()
{
  int n,i;
  long long t=0,res=0;
  long long a[N_MAX];
  cin >> n;
  for(i=0;i<n;i++)
    cin >> a[i];
  sort(a,a+n,greater<long long>());
  for(i=1;i<n;i++)
    if(a[i]==a[i-1])
      if(t==0){
        t=a[i];
        i++;
      }else{
        res=a[i]*t;
        break;
      }
  cout << res << endl;
  return 0;
}