#include<iostream>
#include<algorithm>
using namespace std;
int N_MAX = 100000;
long long p = 1000000007;
int main()
{
  int n,i;
  long long res=1;
  long long t[N_MAX],a[N_MAX],ma[N_MAX],mi[N_MAX];
  cin >> n;
  for(i=0;i<n;i++){
    cin >> t[i];
    if(i==0 || i>0&&t[i]>t[i-1]){
      ma[i]=t[i];
      mi[i]=t[i];
    }else{
      ma[i]=t[i];
      mi[i]=1;
    }
  }
  for(i=0;i<n;i++)
    cin >> a[i];
  for(i=n-1;i>=0;i--){
    if(i==n-1 || i<n-1&&a[i]>a[i+1]){
      if(ma[i]<a[i]||mi[i]>a[i]){
        cout << "0" << endl;
        return 0;
      }
      ma[i]=a[i];
      mi[i]=a[i];
    }else{
      if(mi[i]>a[i]){
        cout << "0" << endl;
        return 0;
      }
      ma[i]=min(a[i],ma[i]);
    }
  }
  for(i=0;i<n;i++){
    res*=ma[i]-mi[i]+1;
    res%=p;
  }
  cout << res << endl;
  return 0;
}