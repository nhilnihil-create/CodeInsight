#include<iostream>
#include<algorithm>
#include<vector>
#include<queue>
using namespace std;
int main(){
  int n;
  cin>>n;
  int array[105]={0},cnt[105]={0};
  int ma=0;
  for(int i=0;i<n;i++){
    cin>>array[i];
    ma=max(ma,array[i]);
    cnt[array[i]]++;
  }
  if(ma%2==0){
    if(cnt[ma/2]!=1){
      cout<<"Impossible"<<endl;
      return 0;
    }
    for(int i=0;i<ma/2;i++){
      if(cnt[i]>0){
        cout<<"Impossible"<<endl;
        return 0;
      }
    }
    for(int i=ma/2+1;i<=ma;i++){
      if(cnt[i]<2){
        cout<<"Impossible"<<endl;
        return 0;
      }
    }
  }
  else{
    if(cnt[ma/2+1]!=2){
      cout<<"Impossible"<<endl;
      return 0;
    }
    for(int i=0;i<=ma/2;i++){
      if(cnt[i]>0){
        cout<<"Impossible"<<endl;
        return 0;
      }
    }
    for(int i=ma/2+1;i<=ma;i++){
      if(cnt[i]<2){
        cout<<"Impossible"<<endl;
        return 0;
      }
    }
  }
  cout<<"Possible"<<endl;
  return 0;
}
