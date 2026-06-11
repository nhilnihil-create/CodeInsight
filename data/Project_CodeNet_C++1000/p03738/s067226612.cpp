#include<bits/stdc++.h>
#define rep(i,n) for(int i=0;i<(int)(n);i++)
#define reps(i,n) for(int i=1;i<(int)(n);i++)

typedef long long ll;
using namespace std;
int main()
{

  string a,b;
  cin>>a>>b;


  if(a.length()>b.length()){
    cout<<"GREATER"<<endl;
  }else if(a.length()<b.length()){
    cout<<"LESS"<<endl;
  }else{
    rep(i,a.length()){
      if(a[i]>b[i]){
        cout<<"GREATER"<<endl;
        return 0;
      }else if(a[i]<b[i]){
        cout<<"LESS"<<endl;
        return 0;
      }
    }
    cout<<"EQUAL"<<endl;
  }


  return 0;
}
