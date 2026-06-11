#include <bits/stdc++.h>
using namespace std;

int main(){
  int s,c;
  cin >> s >> c;
  vector<pair<int,int>>check(c,pair<int,int>(0,0));
  vector<pair<int,int>>stu(s,pair<int,int>(0,0));
  for(int i=0;i<s;i++)
    cin >> stu.at(i).first >> stu.at(i).second;
  for(int i=0;i<c;i++)
    cin >> check.at(i).first >> check.at(i).second;
  vector<int>ans(s);
  for(int i=0;i<s;i++){
    int64_t near=10e8;
    for(int j=0;j<c;j++){
      if(abs(check.at(j).first-stu.at(i).first)+abs(check.at(j).second-stu.at(i).second)<near){
        near=abs(check.at(j).first-stu.at(i).first)+abs(check.at(j).second-stu.at(i).second);
        ans.at(i)=j;
      }
    }
  }
  for(int i=0;i<s;i++)
    cout << ans.at(i)+1 << endl;
}