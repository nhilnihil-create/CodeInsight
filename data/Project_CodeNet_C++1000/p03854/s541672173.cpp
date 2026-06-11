#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); i++)
#define MAX 10000

using namespace std;
typedef long long ll;


 string devide[4] = {"dream", "dreamer","erase","eraser"};

int main(){

 string s;
 cin>>s;
  reverse(s.begin(),s.end());

  for(int i=0;i<4;i++){
    reverse(devide[i].begin(),devide[i].end());
  }

   bool can = true;

  for(int i=0;i<s.length();)
 {
    bool can2 = false;
    for(int j =0;j<4;j++)
    {
        string d = devide[j];
        if(s.substr(i,d.size()) == d){
            can2 = true;
            i +=d.size(); }
    }

    if(!can2){
        can  = false;
        break; }
  }

  if(can)
    cout<<"YES"<<endl;
  else
    cout<<"NO"<<endl;

 return 0;
}