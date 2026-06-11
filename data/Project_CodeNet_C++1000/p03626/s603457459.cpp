#include<iostream>
#include<string>
#include<iomanip>
#include<cmath>
#include<vector>
#include<algorithm>

using namespace std;

#define int long long
#define endl "\n"

const long long INF = (long long)1e18;
const long long MOD = (long long)1e9 + 7; 

string yn(bool f){return f?"Yes":"No";}
string YN(bool f){return f?"YES":"NO";}



signed main(){
	cin.tie(0);
	ios::sync_with_stdio(false);
	cout<<fixed<<setprecision(10);
	
	int N, ans = 1;
	string s1, s2;
	
	cin>>N;
	cin>>s1>>s2;
	
	for(int i = 0; i < N; i++){
		if(s1[i] == s2[i]){
			if(i){
				if(s1[i-1] == s2[i-1]){
					ans *= 2;
				} else {
					ans *= 1;
				}
			} else {
				ans *= 3;
			}
		} else{
			if(i){
				if(s1[i-1] == s2[i-1]){
					ans *= 2;
				} else {
					ans *= 3;
				}
			} else {
				ans *= 6;
			}
			i++;
		}
		ans %= MOD;
	}
	
	cout<<ans<<endl;
	
	return 0;
}