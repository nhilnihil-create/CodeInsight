#include <bits/stdc++.h>
using namespace std;
#define modulo 1000000007
#define mod(mod_x) ((((long long)mod_x)+modulo)%modulo)
#define Inf 1000000000

//aのb乗
int beki(int a,int b,int M = modulo){
	int x = 1;
	while(b!=0){
		if(b&1){
			x=((long long)x*a)%M;
		}
		a=((long long)a*a)%M;
		b>>=1;
	}
	return x;
}


//aの逆元
int gyakugen(int a){
	return beki(a,modulo-2);
}

struct combi{
	deque<int> kaijou;
	deque<int> kaijou_;
	
	combi(int n){
		kaijou.push_back(1);
		for(int i=1;i<=n;i++){
			kaijou.push_back(mod(kaijou[i-1]*i));
		}
		
		int b=gyakugen(kaijou[n]);
		
		kaijou_.push_front(b);
		for(int i=1;i<=n;i++){
			int k=n+1-i;
			kaijou_.push_front(mod(kaijou_[0]*k));
		}
	}
	
	int combination(int n,int r){
		if(r>n)return 0;
		int a = mod(kaijou[n]*kaijou_[r]);
		a=mod(a*kaijou_[n-r]);
		return a;
	}
	
	int junretsu(int a,int b){
		int x = mod(kaijou_[a]*kaijou_[b]);
		x=mod(x*kaijou[a+b]);
		return x;
	}
	
	int catalan(int n){
		return mod(combination(2*n,n)*gyakugen(n+1));
	}
	
};

vector<int> calc(auto X,auto Y){
	vector<int> ret(X.size(),0);
	
	for(int i=0;i<X.size();i++){
		for(int j=0;j<Y.size();j++){
			int k = i-j;
			if(k<0)break;
			ret[i] = mod(ret[i] + mod(X[k] * Y[j]));
		}
	}
	
	return ret;
}
	
int main(){
	
	int N;
	cin>>N;
	
	string S;
	cin>>S;
	
	int K = N-S.size();
	
	combi C(100000);
	
	vector<vector<int>> X(13,vector<int>(K/2+1,0));
	
	for(int i=0;i<13;i++){
		if(i==0){
			for(int j=0;j<X[i].size();j++){
				if(j==0)X[i][j] = 1;
				else{
					X[i][j] = mod(C.catalan(j)*beki(2,j));
				}
			}
		}
		else{
			X[i] = calc(X[i-1],X[i-1]);
		}
	}
	
	int A = S.size();
	vector<int> ans(K/2+1,0);
	ans[0] = 1;
	
	for(int i=0;i<13;i++){
		if((1<<i)&A){
			ans = calc(ans,X[i]);
		}
	}
	
	vector<vector<int>> dp(5001,vector<int>(5001,0));
	dp[0][0] = 1;
	
	
	for(int i=0;i<5000;i++){
		for(int j=0;j<=5000;j++){
			if(j!=5000){
				dp[i+1][j+1] = mod(dp[i+1][j+1] + mod(2*dp[i][j]));
			}
			int k = max(j-1,0);
			dp[i+1][k] = mod(dp[i+1][k] + dp[i][j]);
		}
	}
	
	int ANS = 0;
	
	for(int i=0;i<ans.size();i++){
		int temp = K - i*2;
		ANS = mod(ANS + mod(ans[i] * dp[temp][0]));
	}
	
	cout<<ANS<<endl;
	
    return 0;
}
