#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef double dd;
const int mod=1e9+7;
const int N = 1e5+5;

string now;

int main(){
  // freopen("input.txt","r",stdin);
  cin>>now;
  if(now.size() == 2){
    if(now[0] == now[1]) cout<<"1 2"<<endl;
    else cout<<"-1 -1"<<endl;
    return 0;
  }
  for(int i = 0;i < now.size();i++){
    if(i+1 < now.size() && now[i] == now[i+1]) {
      cout<<i+1<<" "<<i+2<<endl;
      return 0;
    }
    else if(i+2 < now.size() && now[i] == now[i+2]){
      cout<<i+1<<" "<<i+3<<endl;
      return 0;
    }
  }
  cout<<"-1 -1"<<endl;
  return 0;
}
