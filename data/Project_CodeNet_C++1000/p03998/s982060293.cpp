#include <bits/stdc++.h>
#define fast ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
using namespace std;
#define ll long long 
#define pb push_back
#define mp make_pair


void solve(){
 	
 	string s1,s2,s3;
 	cin>>s1>>s2>>s3;
 	queue<char> sa,sb,sc;
 	for(int i=0;i<s1.size();i++){
 		sa.push(s1[i]);
 	}
 	for(int i=0;i<s2.size();i++){
 		sb.push(s2[i]);
 	}
    for(int i=0;i<s3.size();i++){
 		sc.push(s3[i]);
 	}
 	char pop='a';
  int t=1;
 while(t ){
 	if(pop=='a'  ){
 		if(sa.empty()){ cout<<"A"<<endl; return ;}
 		 pop=sa.front();
 		 sa.pop();
 	}
 	else if(pop=='b'  ){
 		if(sb.empty()){ cout<<"B"<<endl; return ;}
 		 pop=sb.front();
 		 sb.pop();
 	}
 	else if(pop=='c'  ){
 		if(sc.empty()){ cout<<"C"<<endl; return ;}
 		 pop=sc.front();
 		 sc.pop();
 	}


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