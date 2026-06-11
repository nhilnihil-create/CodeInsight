#include <bits/stdc++.h>
using namespace std;

int main() {
  int N;
  cin>>N;
  vector<int> a(N);
  vector<int> b(N);
  for(int i=0;i<N;i++)
    cin>>a.at(i);
  int c=0;
  int s=1;
  while(true) {
    s=a.at(s-1);
    c++;
    if(s==2) {
      cout<<c<<endl;
      break;
    }
    if (b.at(s-1)==1) {
      cout<<"-1"<<endl;
      break;
    }
    b.at(s-1)=1;
  }
}