#include<iostream>
#include<string>
#include<vector>
using namespace std;

int main(){
  string s;cin>>s;
  vector<int> c(4,0);
  for(int i=0;i<(int)s.size();i++){
    if(s[i]=='N') c[0]++;
    if(s[i]=='W') c[1]++;
    if(s[i]=='S') c[2]++;
    if(s[i]=='E') c[3]++;
  }
  if(((c[0]>0&&c[2]>0)||(c[0]==0&&c[2]==0))&&((c[1]>0&&c[3]>0)||(c[1]==0&&c[3]==0))){
    cout<<"Yes"<<endl;
  }else{
    cout<<"No"<<endl;
  }
}