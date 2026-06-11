#include<bits/stdc++.h>
using namespace std;

int main(){
  int n,k;
  vector<int> snake;
  cin>>n>>k;
  for(int i=0;i<n;i++){
    int a;
    cin>>a;
    snake.push_back(a);
  }
  sort(snake.begin(),snake.end(),greater<int>());
  int ans=0;
  for(int i=0;i<k;i++){
    ans+=snake[i];
  }
  cout<<ans<<endl;
}