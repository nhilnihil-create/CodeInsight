#include<bits/stdc++.h>
using namespace std;
int main(){
	int n;cin>>n;
  set<int >s;
  for(int i=0,a;i<n;i++){
  	cin>>a;
    if(s.find(a)==s.end())s.insert(a);
    else s.erase(a);
  }
  cout<<s.size();
}