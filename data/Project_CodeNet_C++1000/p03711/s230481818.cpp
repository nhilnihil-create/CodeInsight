#include <bits/stdc++.h>
using namespace std;
const int64_t INF=999999999;

int main() {
   int x,y;
   cin>>x>>y;
   vector<int>t={1,3,1,2,1,2,1,1,2,1,2,1,};
   //左からの番号の値がその番号の所属。
   if(t[x-1]==t[y-1]){cout<<"Yes"<<endl;}
   else{cout<<"No"<<endl;}
   
return 0;}