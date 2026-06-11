#include <bits/stdc++.h>
#define ll long long 
using namespace std;

#define pb push_back
void solve(){
  string s; cin>> s;
  int a,z,ca=1;
  for(int i=0;i<(int)s.size();++i){
    if(s[i]=='A' && ca) a=i,ca=0;
    if(s[i]=='Z') z=i;
  }
  cout<<z-a+1<<endl;
}


int main() {
   #ifndef ONLINE_JUDGE
  freopen("input.txt","r",stdin);
  freopen("output.txt","w",stdout);
  #endif

 ios_base::sync_with_stdio(0);
 cin.tie(0);

int t=1 ;  while(t--)
 solve();

return 0;
}
