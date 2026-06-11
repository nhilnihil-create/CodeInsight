#include <iostream>
#include <algorithm>
#include <queue>
#include <stack>
#include <cassert>
using namespace std; typedef long long ll; const int MINF=-1e9; typedef pair<int,int> P;

int main() {
  ll lo,oo,u1,u2; cin>>lo>>oo>>u1>>u1>>u2;
  ll an=0;
  an = max(an,(lo/2)*2+(u1/2)*2+(u2/2)*2);
  if (lo>0 && u1>0 && u2>0) an = max(an,(lo-1)/2*2+(u1-1)/2*2+(u2-1)/2*2+3);
  an+=oo;
  cout<<an<<endl;
}