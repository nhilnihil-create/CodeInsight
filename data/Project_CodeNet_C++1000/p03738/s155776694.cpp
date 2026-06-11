#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
using ll = long long;

int main() {
  string a,b;
  cin>>a>>b;
  if(a.size()>b.size()){
    cout<<"GREATER"<<endl;
  }else if(a.size()<b.size()){
    cout<<"LESS"<<endl;
  }else{
    rep(i,a.size()){
      if(a.at(i)>b.at(i)){
        cout<<"GREATER"<<endl;
        return 0;
      }else if(a.at(i)<b.at(i)){
        cout<<"LESS"<<endl;
        return 0;
      }
      if(a.at(a.size()-1)==b.at(b.size()-1)){
        cout<<"EQUAL"<<endl;
        return 0;
      }
    }
  }
}