#include <bits/stdc++.h>
using namespace std;
int main () {
  int N;
  cin>>N;
  vector<int>a(N);
 for(int i=0;i<N;i++){
   cin>>a.at(i);
 }
  int i=1;
  int c=0;
 while(i!=2){
   i=a.at(i-1);
  c++;
   if(c>N){
     cout<< -1 <<endl;
     break;
   }
 }
  if(c<=N){
    cout<< c << endl;
  }
}
