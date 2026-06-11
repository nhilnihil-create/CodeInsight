#include <bits/stdc++.h>
#define fast ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
using namespace std;
#define ll long long 
#define pb push_back
#define mp make_pair


void solve(){
 	
 	string s1,s2,s3;
 	queue<int> q[3];
   for(int i=0;i<3;i++){
     string s;cin>>s; 
     for(int j=0;j<s.size();j++){
         q[i].push(s[j]-'a');
     }
   }
 	int pop=0;
 while(1){
    
  if(q[pop].empty()) {cout<<(char)('A'+pop)<<endl; return;} 
  int t=q[pop].front();
  q[pop].pop();
  pop=t;
   
}
 	
}



int main(){
  #ifndef ONLINE_JUDGE
  freopen("input.txt","r",stdin);
  freopen("output.txt","w",stdout);
  #endif

  fast
  ll t=1;
 
  while(t--){
  	solve();
  }

return 0;
  
}