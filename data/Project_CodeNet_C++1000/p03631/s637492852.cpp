#include<bits/stdc++.h>
using namespace std;
int main(){
  string n;
  cin>>n;
  bool f=1;
  for(int i=0;i<n.size();i++)
    f=(n.at(i)!=n.at(n.size()-1-i)?0:f);
  cout<<(f?"Yes":"No")<<endl;
}