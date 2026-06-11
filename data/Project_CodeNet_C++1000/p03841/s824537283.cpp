#include <bits/stdc++.h>
#define ll long long
using namespace std;

int main(){
  int n;
  cin>>n;
  int ans[n*n];
  for(int i=0;i<n*n;i++){
    ans[i]=0;
  }
  int vec[n];
  int copyvec[n];
  for(int i=0;i<n;i++){
    cin>>vec[i];
    copyvec[i]=vec[i];
    ans[vec[i]-1]=i+1;
  }
  int vecb[n];
  for(int i=0;i<n;i++){
    vecb[i]=i;
  }
  sort(copyvec,copyvec+n);
  int vecc[n];
  for(int i=0;i<n;i++){
    for(int j=0;j<n;j++){
      if(copyvec[i]==vec[j]){
        vecc[i]=j;
      }
    }
  }
  for(int i=0;i<n;i++){
    for(int j=0;j<vec[vecc[i]];j++){
      if(ans[j]==0){
        if(vecb[vecc[i]]>0){
          ans[j]=vecc[i]+1;
          vecb[vecc[i]]--;
          if(vecb[vecc[i]]==0){
            break;
          }
        }
      }
    }
  }
  for(int i=0;i<n;i++){
    vecb[i]=n-i-1;
  }
  for(int i=n*n-1;i>=0;i--){
    if(ans[i]==0){
      for(int j=n-1;j>=0;j--){
        if(vecb[vecc[j]]>0){
          ans[i]=vecc[j]+1;
          vecb[vecc[j]]--;
          break;
        }
      }
    }
  }
  int x[n+3];
  for(int i=0;i<n+3;i++){
    x[i]=0;
  }
  for(int i=0;i<n*n;i++){
    x[ans[i]]++;
    if(x[ans[i]]==ans[i]){
      if(i+1!=vec[ans[i]-1]){
        cout<<"No"<<endl;
        return 0;
      }
    }
  }
  for(int i=1;i<n;i++){
    if(x[i]!=n){
      cout<<"No"<<endl;
      return 0;
    }
  }
  cout<<"Yes"<<endl;
  for(int i=0;i<n*n;i++){
    cout<<ans[i]<<" ";
  }
  cout<<endl;
  return 0;
}