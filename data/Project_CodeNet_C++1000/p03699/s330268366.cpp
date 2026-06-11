#include <bits/stdc++.h>
using namespace std;

int main() {
int n;
cin>>n;
vector<int> s(n);
int a=0;
int b=0;
int x=0;
int y=0;
int minn =1000;
for(int i=0;i<n;i++){
  cin>>s[i];
  y+=s[i];
  if(s[i]%10==0){
    a++;
  }
  else if(s[i]%10!=0){
    b++;
    x+=s[i];
    minn=min(minn,s[i]);
  }
}
if(a==n){
  cout<<0<<endl;
}
else if(b==n){
  cout<<x<<endl;
}else if(y%10!=0){
  cout<<y<<endl;
}
else{
  cout<<y-minn<<endl;
}

  return 0;
}

