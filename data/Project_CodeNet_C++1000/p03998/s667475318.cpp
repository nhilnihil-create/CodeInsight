#include<bits/stdc++.h>
using namespace std;
using ll=int64_t;
int main(){
  vector<string> b(3);
  vector<int> l(3),p(3);
  char z;
  int j,y=0;
  for(j=0;j<3;j++){
    cin>>b[j];
    l[j]=b[j].length();
  }
  while(p[y]<l[y]){
    z=b[y][p[y]];
    p[y]++;
    y=z-'a';
  }
  cout<<(char)('A'+y)<<endl;
}