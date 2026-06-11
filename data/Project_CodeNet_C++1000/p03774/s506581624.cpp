#include <bits/stdc++.h>
using namespace std;

int main() {
  int n,m;
  cin>>n>>m;

  vector<vector<int>> start(n,vector<int>(2));
  for(int i=0;i<n;i++){
    cin>>start.at(i).at(0)>>start.at(i).at(1);
  }
  vector<vector<int>> goal(m,vector<int>(2));
  for(int i=0;i<m;i++){
    cin>>goal.at(i).at(0)>>goal.at(i).at(1);
  }

  for(int i=0;i<n;i++){
    int mindis=1e+9;
    int next=-1;
    for(int j=0;j<m;j++){
      int dis=abs(start.at(i).at(0)-goal.at(j).at(0))+abs(start.at(i).at(1)-goal.at(j).at(1));
      if(dis<mindis){
        mindis=dis;
        next=j+1;
      }
    }
    cout<<next<<endl;
  }
}
