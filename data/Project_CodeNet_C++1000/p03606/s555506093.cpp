#include <bits/stdc++.h>
using namespace std;


int main(){
  int N;
  cin>>N;
 int sum =0;
  
  for(int i=0;i<N;i++){
    int X,Y;
    cin>>X>>Y;
    sum+=Y-X+1;
  }
  cout<<sum<<endl;
}