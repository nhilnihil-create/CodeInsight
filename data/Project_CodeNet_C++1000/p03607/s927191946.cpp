#include <bits/stdc++.h>
using namespace std;

int main(){
int n;
  cin >> n;
int j=0;  
int a[100000];
  for(int i=0;i<n;i++) cin >> a[i];
sort(a,a+n);
  int res=0;
  int f;
  while(j<n){
   int cc=a[j];
   f=0;
    while(j<n && a[j]==cc){
      j++;
      f++;     
      }
    res+=f%2;
  
  }
 cout << res << endl; 


}
