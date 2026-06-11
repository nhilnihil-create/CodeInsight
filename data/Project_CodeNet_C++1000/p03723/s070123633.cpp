#include <bits/stdc++.h>
using namespace std;

int main() {
  int A,B,C;
  cin>>A>>B>>C;
  vector<int>x={A,B,C};
  for(int i=0;i<1000000;i++){
    if(x.at(0)%2==1||x.at(1)%2==1||x.at(2)%2==1){
      cout<<i<< endl;
      return 0;
    }
    int a=x.at(0);
    int b=x.at(1);
    int c=x.at(2);
    x.at(0)=b/2+c/2;
    x.at(1)=a/2+c/2;
    x.at(2)=a/2+b/2;
  }
  cout<<"-1"<< endl;
}
