#include <bits/stdc++.h>
using namespace std;
using ll=long long;
using vi = vector<int>;
using vvi = vector<vector<int>>;
using vl = vector<ll>;
using vvl = vector<vector<ll>>;
#define MOD 1000000007ULL;
#define rep(i,n) for(int i=0;i<n;i++)

int main() {
	string S;
  	cin>>S;
  	
  	string divide[4]= {"dream","dreamer","erase","eraser"};
  	
  	reverse(S.begin(),S.end());
  	rep(i,4) reverse(divide[i].begin(),divide[i].end());
	  	
  	bool can=true;
  	for(int i=0;i<S.size();){
     	bool can2=false;
      	for(int j=0;j<4;j++){
         	string d =divide[j];
          	if(S.substr(i,d.size())==d){
            	can2=true;
              	i+=d.size();
            }
        }
      	if(!can2){
         	can=false;
          	break;
        }
    }
  
  	if(can) cout<<"YES"<<endl;
  	else cout<<"NO"<<endl;
}