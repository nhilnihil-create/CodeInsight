#include <bits/stdc++.h>
using namespace std;



int main(){
  int N;
  cin>>N;
  
  vector<int> vec(8);
  int nizi=0;
  for(int i=0;i<N;i++){
    int a;
    cin>>a;
    if(a/400==0) vec.at(0)++;
    else if(a/400==1) vec.at(1)++;
    else if(a/400==2) vec.at(2)++;
    else if(a/400==3) vec.at(3)++;
    else if(a/400==4) vec.at(4)++;
    else if(a/400==5) vec.at(5)++;
    else if(a/400==6) vec.at(6)++;
    else if(a/400==7) vec.at(7)++;
    else if(a/400>=8) nizi++;
  }
  int sai=0;
  for(int i=0;i<8;i++){
    if(vec.at(i)>=1) sai++;
  }
  int deka=sai+nizi;
  if(sai==0&&nizi>=1) sai=1;
  cout<<sai<<" "<<deka<<endl;
    
  
}