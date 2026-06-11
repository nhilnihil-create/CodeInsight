#include<iostream>
#include<vector>
using namespace std;
int main(){

  int N;
  cin>>N;
  vector<int>a(N);
  vector<int>visit(N+1);
  for(int i=0;i<=N-1;i++){
  
    cin>>a[i];
  }
  int next=1;
  int ans=0;
  while(1){
    
    if(visit[next]==1){
    
      cout<<-1;
      return 0;
    }
    visit[next]=1;
    next=a[next-1];
    if(next==2)break;
    else ans++;
  }
  cout<<ans+1;
}