#include <iostream>
#include <bits/stdc++.h>
using namespace std;
typedef int64_t llo;
#define mp make_pair
#define pb push_back
#define a first
#define b second
void setIO(string name) {
	ios_base::sync_with_stdio(0); cin.tie(0);
	freopen((name+".in").c_str(),"r",stdin);
	freopen((name+".out").c_str(),"w",stdout);
}
int n;
string s;
int dp[200003];
int ind[26][200003];
int aa[200003];
int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cin>>s;
	int n=s.size();
	for(int i=0;i<n;i++){
		aa[i]=s[i]-'a';
	}
//	string ss="abcdefghijklmnopqrstuvwxyz";
	string ss="abcdefghijklmnopqrstuvwxyz";
	for(int j=0;j<26;j++){
		int ind2=n;
		for(int i=n-1;i>=0;i--){
			if(aa[i]==j){
				ind2=min(ind2,i);
			}
			ind[j][i]=ind2;
			
		}

	}
	for(int i=n-1;i>=0;i--){
		dp[i]=n;
		for(int j=0;j<26;j++){

			if(ind[j][i]>=n){
				dp[i]=1;
			}
			else if(ind[j][i]==n-1){
				dp[i]=min(dp[i],2);
			}
			else{
				dp[i]=min(dp[i],dp[ind[j][i]+1]+1);
			}
		}
	}
	int ind2=0;
	for(int i=0;i<dp[0];i++){
		for(int j=0;j<26;j++){
			if(ind2>=n){
				cout<<ss[j];
				break;
			}
			if(ind[j][ind2]>=n){
				cout<<ss[j];
				break;
			}
			else{
				if(dp[ind[j][ind2]+1]+i+1==dp[0]){
					cout<<ss[j];
					ind2=ind[j][ind2]+1;
					break;
				}
			}
		}
	}
	//cout<<ind[0][0]<<endl;
	cout<<endl;
	


	return 0;
}