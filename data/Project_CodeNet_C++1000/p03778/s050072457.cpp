#include<bits/stdc++.h>
using namespace std;

int main(){
  int w,a,b;
  cin>>w>>a>>b;
  if(w>=abs(a-b)){ cout<<"0"; return 0; }
  else if(a<b) { cout<<b-a-w; return 0; }
  else cout<<a-b-w;


}
