#include<bits/stdc++.h>
using namespace std;
int main(){
  int n;
  cin>>n;
  vector<int> m(4,0);
  for(int i=0;i<n;i++){
    int a;
    cin>>a;
    m.at(a%4)++;
  }
  cout<<(m.at(1)+m.at(3)<=m.at(0)||(m.at(2)==0&&m.at(1)+m.at(3)<=m.at(0)+1)?"Yes":"No")<<endl;
}