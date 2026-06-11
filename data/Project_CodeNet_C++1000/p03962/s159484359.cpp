#include <bits/stdc++.h>
using namespace std;
int main(){
vector<int>moji(3);
  for(int i=0;i<3;i++){
  cin>>moji.at(i);
  }
  sort(moji.begin(),moji.end());
  int count=1;
   for(int i=1;i<3;i++){
   		if(moji.at(i-1) != moji.at(i)){
        count++;
        }
  }
  cout<<count<<endl;
}