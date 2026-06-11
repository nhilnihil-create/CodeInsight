#include <bits/stdc++.h>
using namespace std;

int main(){
int n;
  cin >> n;
if(n>1){  
int x[n];
  for(int i=0;i<n;i++)cin>>x[i];
sort(x,x+n);  
int num[1000000]={0};
  for(int i=0;i<n;i++){
  num[x[i]-1]++;
  num[x[i]]++;
  num[x[i]+1]++;
 }
  
int max=-1;

for(int i=x[0];i<x[n-1]+1;i++){
  int s=num[i];
  if(s>max)max=s;
} 
cout << max << endl;  
}
else{
  cout << 1 << endl; 
}
  
}
