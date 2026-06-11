#include<bits/stdc++.h>

using namespace std;

int main(){
  vector<string> s(3);
  string t;
  for(int i=0;i<3;i++){
    cin>>s[i];
    char x=s[i][0];
    int y=x-'a';
    x=y+'A';
    t+=x;
  }
  cout<<t<<endl;
}
