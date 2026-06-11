#include<iostream>
#include<algorithm>
#include<set>
using namespace std;

int main(){
  int a,b;
  cin>>a>>b;
  set<int> st1,st2,st3;
  st1.insert(1);
  st1.insert(3);
  st1.insert(5);
  st1.insert(7);
  st1.insert(8);
  st1.insert(10);
  st1.insert(12);
  st2.insert(4);
  st2.insert(6);
  st2.insert(9);
  st2.insert(11);
  if((st1.count(a)&&st1.count(b))||(st2.count(a)&&st2.count(b))) cout<<"Yes";
  else cout<<"No";
}