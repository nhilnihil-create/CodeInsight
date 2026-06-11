#include<bits/stdc++.h>
using namespace std;


int main() {
  int n;
  cin>>n;
  long long a[n];
  long long sum=0;
  for(int i=0;i<n;i++){
    cin>>a[i];
    sum+=a[i];
  }
  sort(a,a+n);
  int count=0;
  int j=0;
  for(int i=n-1;i>=0;i--){ 
    count++;
  	sum-=a[i];
    if(sum*2<a[i]) break;
  }
  cout<<count<<endl;
}