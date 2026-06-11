#include <bits/stdc++.h>
using namespace std;

int main(){
int n,c,k;
  cin >> n >> c >> k;
int t[n];
  for(int i=0;i<n;i++) cin >> t[i];
sort(t,t+n);
  int bus=0;
  
  for(int i=0;i<n;){
  bus++;  
  int j=i;
    while(i-j<c && t[i]-t[j]<=k && i<n)i++;
  
  }
 cout << bus << endl;
}