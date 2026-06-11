#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
using P = pair<int,int>;

int c[3][3];
int a[3];
int b[3];
const int INF = 1001001001;
int main(){
  string A,B;
  cin>>A>>B;
  if(A.size()==B.size()){
  if(A>B){cout<<"GREATER"<<endl;}
  else if(A<B){cout<<"LESS"<<endl;}
  else {cout<<"EQUAL"<<endl;}
  }
  else if(A.size()>B.size()){
      cout<<"GREATER"<<endl;
  }
  else{cout<<"LESS"<<endl;}
  return 0;
}