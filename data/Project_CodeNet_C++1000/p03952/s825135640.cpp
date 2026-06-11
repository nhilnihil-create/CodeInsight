#include<bits/stdc++.h>
using namespace std;
const int INF = 1e9;
int main(){ 
  int N,x; cin >> N >> x;
  
  if( x == 2*N-1 || x == 1){ cout << "No" << endl; return 0;}
  cout << "Yes" << endl;
  
  if( N == 2){ for(int i = 1; i <=3; i++){ cout <<i << endl;} return 0;}
  
  vector<int> ans(2*N-1,INF);
  
  if( x != 2){
  ans[N-2] = x-1; ans[N-1] = x; ans[N] = x+1; ans[N+1] = x-2;}
  else{
  ans[N-2] = x+1; ans[N-1] = x; ans[N] = x-1; ans[N+1] = x+2;}
 
  queue<int> stock; 
  for(int i = 1; i <= 2*N-1; i++){
    if( x != 2){
     if( i == x+1 || i == x || i == x-1 || i == x-2){ continue;}}
    else{
     if( i == x+1 || i == x || i == x-1 || i == x+2){ continue;}}
    
    stock.push(i);}
  
  for(int i = 0; i < 2*N-1; i++){
    if( ans[i] == INF){ ans[i] = stock.front(); stock.pop();}}
  
  for(int i = 0; i < 2*N-1; i++){ cout << ans[i] << endl; }
  
  return 0;}
    
  