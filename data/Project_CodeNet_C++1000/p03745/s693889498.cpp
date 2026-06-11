#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for (int i = 0; i < (int)(n); ++i)
#define rep2(i, s, n) for (int i = (s); i < (int)(n); i++)

int main() {
  int n;
  cin>>n;  
  vector<int>a(n);
  int ans=1;
  rep(i,n){
    cin>>a.at(i);
  }
  int j=0;
  int i=1;
  int k=2;
  while(k<n){
    if((a.at(j)<a.at(i)&&a.at(i)>a.at(k))||(a.at(j)>a.at(i)&&a.at(i)<a.at(k))){
      ans++;
      j=k;
      i=j+1;
      k+=2;
    }
    else if((a.at(j)<a.at(i)&&a.at(i)==a.at(k))||(a.at(j)>a.at(i)&&a.at(i)==a.at(k))){
      k++;
    }
    else{
      k++;
      i=k-1;
      j=k-2;
    }
  } 
  cout<<ans<<endl;
}