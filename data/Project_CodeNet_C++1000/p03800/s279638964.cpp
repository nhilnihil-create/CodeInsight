#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const ll mod = 1000000007;

int main(){
  ll n;
  cin >> n;
  string s;
  cin >> s;
  s+=s[0];
  string A,B,C,D;
  
  vector<char>a(n+2),b(n+2),c(n+2),d(n+2);
  a[0]='S',a[1]='W';
  b[0]='S',b[1]='S';
  c[0]='W',c[1]='W';
  d[0]='W',d[1]='S';
  
  
  for(ll i=1; i<n+1; i++){
    if(s[i]=='o' && a[i]=='S') a[i+1]=a[i-1];
    else if(s[i]=='x' && a[i]=='W') a[i+1]=a[i-1];
    else{
      if(a[i-1]=='W') a[i+1]='S';
      else a[i+1]='W';
    } 
  }
  
  for(ll i=1; i<n+1; i++){
    if(s[i]=='o' && b[i]=='S') b[i+1]=b[i-1];
    else if(s[i]=='x' && b[i]=='W') b[i+1]=b[i-1];
    else{
      if(b[i-1]=='W') b[i+1]='S';
      else b[i+1]='W';
    } 
  }
  
  for(ll i=1; i<n+1; i++){
    if(s[i]=='o' && c[i]=='S') c[i+1]=c[i-1];
    else if(s[i]=='x' && c[i]=='W') c[i+1]=c[i-1];
    else{
      if(c[i-1]=='W') c[i+1]='S';
      else c[i+1]='W';
    } 
  }
  
  for(ll i=1; i<n+1; i++){
    if(s[i]=='o' && d[i]=='S') d[i+1]=d[i-1];
    else if(s[i]=='x' && d[i]=='W') d[i+1]=d[i-1];
    else{
      if(d[i-1]=='W') d[i+1]='S';
      else d[i+1]='W';
    } 
  }
  
  
  if(a[0]==a[n] && a[1]==a[n+1]){
    for(ll i=0; i<n; i++) A+= a[i]; 
    cout << A << endl;
    return 0;
  }
  
  if(b[0]==b[n] && b[1]==b[n+1]){
    for(ll i=0; i<n; i++) B+= b[i];
    cout << B << endl;
    return 0;
  }
  
  if(c[0]==c[n] && c[1]==c[n+1]){
    for(ll i=0; i<n; i++) C+= c[i];
    cout << C << endl;
    return 0;
  }
  
  if(d[0]==d[n] && d[1]==d[n+1]){
    for(ll i=0; i<n; i++) D+= d[i];
    cout << D << endl;
    return 0;
  }
  
  cout << -1 << endl;
  
  
}
  
