#include<bits/stdc++.h>
using namespace std;
#define ll long long
int n,k;
int a[5000];
int sum;
int c;

int main(){

  cin>>n>>k;
  for(int i=0;i<n;i++)
    cin>>a[i];

  sort(a,a+n);
  reverse(a,a+n);
  c = n;
  for(int i=0;i<n;i++){
    if(sum+a[i]<k) sum+=a[i];
    else
      c=n-i-1;
  }

  cout<<c<<endl;

  return 0;

}
