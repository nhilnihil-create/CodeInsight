#include<bits/stdc++.h>
using namespace std;
#define ll long long

int main(){
  int n,i,j;
  cin >> n;
  vector<int> a(n),b(n);
  for(i=0;i<n;i++){
    cin >> a.at(i);
  }
  j=0;
  for(i=n-1;i>=0;i=i-2){
    b.at(j)=a.at(i);
    j++;
  }
  j=n-1;
  for(i=n-2;i>=0;i=i-2){
    b.at(j)=a.at(i);
    j--;
  }
  for(i=0;i<n;i++){
    cout << b.at(i) << " ";
  }
}