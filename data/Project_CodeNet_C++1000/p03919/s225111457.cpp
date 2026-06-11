#include<iostream>
using namespace std;

int main(void)
{
  int h,w;
  cin>>h>>w;
  string s[h][w];
  char ans1;
  int ans2;
  for(int i=0;i<h;i++){
    for(int j=0;j<w;j++){
      cin>>s[i][j];
      if(s[i][j]=="snuke"){
        ans1='A'+j;
        ans2=i+1;
        break;
      }
    }
  }
  cout<<ans1<<ans2<<endl;
  
}
