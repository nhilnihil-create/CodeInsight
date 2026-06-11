#include<bits/stdc++.h>
using namespace std;
int main(){
  set<int>AA;
  set<int>BB;
  set<int>CC;
  AA.insert(1);
  AA.insert(3);
  AA.insert(5);
  AA.insert(7);
  AA.insert(8);
  AA.insert(10);
  AA.insert(12);
  BB.insert(4);
  BB.insert(6);
  BB.insert(9);
  BB.insert(11);
  CC.insert(2);
  int x,y;
  cin>>x>>y;
  if(AA.count(x)==true&&AA.count(y)==true){
    cout<<"Yes"<<endl;
  }
  else if(BB.count(x)==true&&BB.count(y)==true){
    cout<<"Yes"<<endl;
  }
  else if(CC.count(x)==true&&CC.count(y)==true){
    cout<<"Yes"<<endl;
  }
  else{
    cout<<"No"<<endl;
  }
}
  
    