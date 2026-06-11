#include<bits/stdc++.h>
using namespace std;
int main(){
  int n;
  cin >> n;
  int a[n];
  int b=0;
  for(int i=0;i<n;i++){
    cin >> a[i];
    if(a[i]%2==1)b++;
  }
  if(b%2==0)cout << "YES";
  else cout << "NO";
}