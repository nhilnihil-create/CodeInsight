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
 char d=s[s.size()-1];
 int n=s.size();
 ll count{}; 
 for(int i=n-1;i>=0;i--){
    if(s[i]!=d) {
      count++;
      d=s[i];
    }
 }
 cout<<count<<endl;
 return 0;
}
