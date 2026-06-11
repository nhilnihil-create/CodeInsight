#include "bits/stdc++.h"
using namespace std;

int main(){
  int n,m;
  cin>>n>>m;
  vector<int> a;
  vector<int> b;
  for(int i=0;i<m;i++){
    int x;
    cin>>x;
    if(x%2==0){
      a.push_back(x);
    }else{
      b.push_back(x);
    }
  }
  if(b.size()>2){
    cout<<"Impossible"<<endl;
    return 0;
  }

  if(b.size()>0)a.insert(a.begin(),b[0]);
  if(b.size()>1)a.push_back(b[1]);

  for(int i=0;i<m;i++){
    cout<<a[i];
    if(i!=m-1)cout<<" ";
  }
  cout<<endl;

  if(m==1){
    if(a[0]!=1){
      cout<<2<<endl;
      cout<<a[0]-1<<" "<<1<<endl;
    }else{
      cout<<1<<endl;
      cout<<1<<endl;
    }
    return 0;
  }

  vector<int> ans;
  if(a[0]-1>0)ans.push_back(a[0]-1);
  for(int i=1;i<m-1;i++){
    ans.push_back(a[i]);
  }
  ans.push_back(a[m-1]+1);

  cout<<ans.size()<<endl;

  for(int i=0;i<ans.size();i++){
    cout<<ans[i];
    if(i!=ans.size()-1)cout<<" ";
  }
  cout<<endl;


}
