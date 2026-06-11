#include <bits/stdc++.h>
using namespace std;

int main(){
  int n,m;
  cin >> n >> m;
  vector<pair<int,int>>point(m);
  vector<pair<int,int>>stu(n);
  for(int i=0;i<n;i++)
    cin >> stu.at(i).first >> stu.at(i).second;
  for(int i=0;i<m;i++)
    cin >> point.at(i).first >> point.at(i).second;
  for(int i=0;i<n;i++){
    int d=1e9,re=0;
    for(int j=m-1;j>=0;j--){
      if(abs(point.at(j).first-stu.at(i).first)+abs(point.at(j).second-stu.at(i).second)<=d){
        d=abs(point.at(j).first-stu.at(i).first)+abs(point.at(j).second-stu.at(i).second);
        re=j+1;
      }
    }
    cout << re << endl;
  }
  return 0;
}