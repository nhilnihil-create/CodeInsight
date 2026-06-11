#include <bits/stdc++.h>
using namespace std;

int main(){
  int n,pair=0; cin>>n;
  vector<bool> flag(100001,false);
  for(int i=0;i<n;i++){
    int a; cin>>a;
    if(flag[a]) pair++;
    else flag[a]=true;
  }
  n-=pair;
  if(n%2==0) n--;
  cout<<n<<endl;
}