#include <bits/stdc++.h>
#define ll long long 
using namespace std;




int main() {
   #ifndef ONLINE_JUDGE
  freopen("input.txt","r",stdin);
  freopen("output.txt","w",stdout);
  #endif
 ios_base::sync_with_stdio(0);
 cin.tie(0);
 cout.tie(0);
 string s; cin>>s;
  auto it=unique(begin(s),end(s))-begin(s)-1;
  cout<<it<<endl;
 return 0;
}
