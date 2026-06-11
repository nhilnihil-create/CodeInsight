#include<bits/stdc++.h>
using namespace std;
int main(){
  string s;cin>>s;
  deque<char>ans;
  int size=s.size();
  for(int i=0;i<size;i++){
    if(s.at(i)=='0')ans.push_back('0');
    else if(s.at(i)=='1')ans.push_back('1');
    else{
      if(ans.empty())continue;
      ans.pop_back();
    }
  }
  while(!ans.empty()){
    cout <<ans.front();
    ans.pop_front();
  }
  cout <<endl;
}