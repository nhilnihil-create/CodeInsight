#include <bits/stdc++.h>
using namespace std;
#include <math.h>
#include <iomanip>
const int INF=1001001001;

int main() {
  int N;
  string S;
  cin>>N>>S;
  int stack=0,l=0;
  for(int i=0;i<N;i++){
    if(S[i]=='('){stack++;}
    else if(stack>0){stack--;}
    else{l++;}
  }
  int r=stack;
  string ans;
  for(int i=0;i<l;i++){
    ans+='(';
  }
  ans+=S;
  for(int i=0;i<r;i++){
    ans+=')';
  }
  cout<<ans<<endl;
  return 0;
}