#include<iostream>
#include<algorithm>
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
  reverse(begin(s),end(s));
  for(auto &e:strs){
    reverse(begin(e),end(e));
  }
  int i;
  for(i=0;;){
    bool updated=false;
    for(auto e:strs){
      if(i+e.size()<=s.size()&&s.compare(i,e.size(),e)==0){
	i+=e.size();
	updated=true;
      }
    }
    if(!updated)break;
  }
  cout<<((i==s.size())?"YES":"NO")<<endl;
}
