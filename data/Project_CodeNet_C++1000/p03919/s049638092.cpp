#include<bits/stdc++.h>
#define int long long
#define rep(i,n) for(int i=0;i<n;i++)
using namespace std;
string a[26][26];
signed main(){
	int h,w,cnt=0;
	cin>>h>>w;
		rep(i,h){
			rep(j,w){
				cin>>a[i][j];
			}
		}
		rep(i,h){
			rep(j,w){
				if(a[i][j]=="snuke")cout<<char(j+'A')<<i+1<<endl;
			}
		}
}
		
		
