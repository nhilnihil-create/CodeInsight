#include<bits/stdc++.h>
using namespace std;
constexpr int64_t mod=1e9+7;

int main()
{
  int h,w;
  cin>>h>>w;
  std::map<char, int> map;
  for (int i = 0; i < h; ++i)
  {
    for (int j = 0; j < w; ++j)
    {
      char a;
      cin>>a;
      map[a]++;
    }
  }

  priority_queue<pair<int,char>> que;
  for(auto&& e: map) {
    que.push(make_pair(e.second,e.first));
  }
    


  if(h%2==0 && w%2==0){
    /*
    for(auto&& e: map) {
      if(e.second%4!=0){
        cout<<"No";
        return 0;
      }
    }
    cout<<"Yes";
    return 0;
    */
    for (int i = 0; i < (h*w)/4; ++i)
    {
      pair<int,char> tmp=que.top();
      que.pop();
      tmp.first-=4;
      if(tmp.first>0) que.push(tmp);
      else if(tmp.first<0) {
        cout<<"No";
        return 0;
      }
    }
    if(que.empty()) cout<<"Yes";
    else cout<<"No";
    return 0;
  }

//
  else if(h%2==0 || w%2==0){
    int even=(h%2==0? h:w);
    even/=2;
    for (int i = 0; i < (h*w-even*2)/4; ++i)
    {
      pair<int,char> tmp=que.top();
      que.pop();
      tmp.first-=4;
      if(tmp.first>0) que.push(tmp);
      else if(tmp.first<0){
        cout<<"No";
        return 0;
      }
    }
    for (int i = 0; i < even; ++i)
    {
      pair<int,char> tmp=que.top();
      que.pop();
      tmp.first-=2;
      if(tmp.first>0) que.push(tmp);
      else if(tmp.first<0){
        cout<<"No";
        return 0;
      }
    }
    if(que.empty()) cout<<"Yes";
    else cout<<"No";
    return 0;
  }

  int cnt_2=(w-1+h-1)/2;
  int cnt_1=1;
  int cnt_4=(h*w-cnt_2*2-cnt_1)/4;
  for (int i = 0; i < cnt_4; ++i)
  {
    pair<int,char> tmp=que.top();
    que.pop();
    tmp.first-=4;
    if(tmp.first>0) que.push(tmp);
    else if(tmp.first<0){
      cout<<"No";
      return 0;
    }
  }
  for (int i = 0; i < cnt_2; ++i)
  {
    pair<int,char> tmp=que.top();
    que.pop();
    tmp.first-=2;
    if(tmp.first>0) que.push(tmp);
    else if(tmp.first<0){
      cout<<"No";
      return 0;
    }
  }
  pair<int,char> tmp=que.top();
  que.pop();
  tmp.first-=1;
  if(tmp.first>0) que.push(tmp);
  else if(tmp.first<0) {
    cout<<"No";
    return 0;
  }

  if(que.empty()) cout<<"Yes";
  else cout<<"No";
} 