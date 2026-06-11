#include <iostream>
#include <algorithm>
#include <queue>
#include <set>
#include <string>
using namespace std; typedef long long ll; const int INF=100; typedef pair<int,int> P;
const int ld=10;

int main() {
  string s; cin>>s; int n=s.size(), an=n;
  for(char i='a';i<='z';i++) {
    int sm=0;
    string s2=s;
    bool in=false;
    for(char ch:s2) {
      if (ch==i) in=true;
    }
    if (!in) continue;
    while(true) {
      bool end=true;
      for(int j=0;j<n-sm;j++) {
        if (s2[j] != i) {end=false; break;}
      }
      if (end) break;
      for(int j=0;j<n-sm-1;j++) {
        if (s2[j]==i || s2[j+1]==i) s2[j]=i;
      }
      //cout<<s2<<endl;
      sm++;
    }
    //cout<<i<<" "<<sm<<endl;
    an=min(an,sm);
  }
  cout<<an<<endl;
}