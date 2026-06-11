#include<iostream>
#include<string>

using namespace std;

int main(){
  string s;
  cin>>s;
  string strs[]={
    "dream",
    "dreamer",
    "erase",
    "eraser"
  };
  bool dp[100001]={true};
  for(int i=0;i<s.size();i++){
    for(auto e:strs){
      int n=i+e.size();
      if(n<=s.size()&&!s.compare(i,e.size(),e)){
	dp[n]|=dp[i];
      }
    }
  }
  cout<<(dp[s.size()]?"YES":"NO")<<endl;
}
