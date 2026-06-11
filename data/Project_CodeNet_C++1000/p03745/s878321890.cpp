#include<iostream>

using namespace std;

int main(){
  int N;
  cin >> N;
  int seq[N];
  for(int i=0;i<N;i++) cin >> seq[i];
  int flag;
  int ans=0;
  if(seq[0]<seq[1]){flag=0;}
  if(seq[0]>seq[1]){flag=1;}
  if(seq[0]==seq[1]){flag=-1;}
  for(int i=1;i<N-1;i++){
    if(seq[i]==seq[i+1]) {continue;}
    if(seq[i]<seq[i+1]){
      if(flag==1){
        ans++;
        flag=3;
      }
      else flag=0;
    }
    if(seq[i]>seq[i+1]){
      if(flag==0){
        ans++;
        flag=4;
      }
      else flag=1;
    }
  }
  cout << ans+1 << endl;
}
