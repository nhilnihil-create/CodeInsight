#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <unordered_map>
#include <cstring>
#include <ctime>
#include <queue>
#include <map>
#include <stack>
using namespace std;
typedef long long ll;
const int maxn = 105;
const int mod = 1000000007;

int main() {
 // freopen("in.cpp","r",stdin);
  ll ret=1;
  int n;
  cin>>n;
  stack<int>st;
  for(int i=1;i<=n;i++){
    int x;
    cin>>x;
    if(st.empty())st.push(1);
    else{
      if(st.top()==x-1){
        ret=ret*(st.size()+1)%mod;
      } else st.push(st.top()+2);
    }
    //cout<<i<<" "<<st.size()<<endl;
  }
  while(!st.empty()){
    ret=ret*st.size()%mod;
    st.pop();
  }
  cout<<ret<<endl;
  return 0;
}
