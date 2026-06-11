#include <bits/stdc++.h>
using namespace std;

int main(){
  int n,a,b; cin>>n>>a>>b;
  long long min_v=(long long)a*(n-1)+b;
  long long max_v=(long long)b*(n-1)+a;
  cout<<(max_v-min_v+1>=0 ? max_v-min_v+1:0)<<endl;
}