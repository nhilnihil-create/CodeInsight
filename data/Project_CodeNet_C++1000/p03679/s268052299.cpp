//#define _GLIBCXX_DEBUG

#include<bits/stdc++.h>
using namespace std;
const int INF= 1e9+5;
typedef long long ll;

int main(){
  int x,a,b;
  cin>>x>>a>>b;
  if(x+a<b)cout<<"dangerous"<<endl;
  else if(b<=a)cout<<"delicious"<<endl;
  else cout<<"safe"<<endl;
}