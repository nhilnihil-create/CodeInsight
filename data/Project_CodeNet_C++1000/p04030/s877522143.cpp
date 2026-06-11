#include<bits/stdc++.h>
using namespace std;
using ll=int64_t;
int main(){
  string z;
  vector<char> x(10);
  cin>>z;
  int l=z.length(),p=0,j;
  for(j=0;j<l;j++){
    if(z[j]!='B'){
      x[p]=z[j];
      p++;
    }
    else if(p>0){
      x[p]=0;
      p--;
    }
  }
  for(j=0;j<p;j++) cout<<x[j];
  cout<<endl;
}