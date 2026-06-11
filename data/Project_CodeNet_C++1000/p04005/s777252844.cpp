#include <bits/stdc++.h>
using namespace std;
int main(){
  long long A,B,C;
  cin>>A>>B>>C;
  vector<long long>v{A,B,C};
  sort(v.begin(),v.end());
  if(A%2==1&&B%2==1&&C%2==1){
    cout<<v[0]*v[1]<<endl;
  }
  else{
    cout<<0<<endl;
  }
}