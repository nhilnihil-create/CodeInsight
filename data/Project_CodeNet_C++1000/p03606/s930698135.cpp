#include <bits/stdc++.h>
using namespace std;

int main(){
 int N; cin >>N;
  int sum=0;
 for(int i=0;i<N;i++){
   int x,y; cin>>x>>y;
   sum+=y-x+1;
 }
  cout <<sum<<endl;


}