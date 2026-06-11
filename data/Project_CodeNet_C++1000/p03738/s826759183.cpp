#include <bits/stdc++.h>
#define rep(i,n) for(int i=0;i<(n);i++)
#define all(v) v.begin(),v.end()
using namespace std;
typedef long long ll;
 
int main(){
  string A,B;
  cin>>A>>B;
  if(A.length()>B.length()){
    cout<<"GREATER";
    return 0;
  }
  if(A.length()<B.length()){
    cout<<"LESS";
    return 0;
  }
  if(A.length()==B.length()){
    rep(i,A.length()){
      if(A[i]>B[i]){
        cout<<"GREATER";
        return 0;
      }
      if(A[i]<B[i]){
        cout<<"LESS";
        return 0;
      }
    }
  }
  cout<<"EQUAL"<<endl;
}   