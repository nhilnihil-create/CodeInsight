#include<iostream><string>
using namespace std;
int main(){

  int N;
  cin>>N;
  string S;
  cin>>S;
  int count=0;
  int max=0;
  for(int i=0;i<=N-1;i++){
  
    if(S[i]=='I')count++;
    else if(S[i]=='D')count--;
    if(count>max)max=count;
  }
  cout<<max;
  return 0;
}