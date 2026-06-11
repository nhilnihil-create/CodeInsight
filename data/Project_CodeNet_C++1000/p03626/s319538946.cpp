#include<iostream>
#include<algorithm>
#include<numeric>
#include<vector>
#include<set>
#include<map>
#include<math.h>
#include <string>
#define cinf(n,x) for(int i=0;i<(n);i++) cin >> x[i];
typedef long long int ll;
using namespace std;
ll mod=1e9+7;
int main(){
 	int n; cin >>n;
 	string s1,s2; cin >>s1 >> s2;
 	bool flag=false; // s1[i]== s2[i]
 	bool flag1=false; // s[i]==s[i+1]
 	ll ans=1;
 	for(int i=0;i<s1.size();i++){
 		if(s1[i]==s2[i]){
 			if(!flag&&!flag1){
 				ans=ans*3%mod;
 				flag=true;
 			}
 			else if(!flag&&flag1){
 				flag1=false;
 				flag=true;
 			}
 			else if(flag&&!flag1){
 				ans=ans*2%mod;
 			}
 		}
 		else{
 			if(!flag&&!flag1){
 				ans=ans*6%mod;
 				flag1=true;
 			}
 			else if(!flag&&flag1){
 				ans=ans*3%mod;
 			}
 			else if(flag&&!flag1){
 				flag=false;
 				flag1=true;
 				ans=ans*2%mod;
 			}
 			i++;
 		}
 	}
 	cout << ans << endl;
 }