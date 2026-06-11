#include <bits/stdc++.h>
using namespace std;
#define modulo 998244353
#define mod(mod_x) ((((long long)mod_x+modulo))%modulo)
#define Inf 1000000000

int main(){
	
	int H,W,d;
	cin>>H>>W>>d;
	
	int K = 500;
	
	vector<string> S(2000,string(2000,'.'));
	
	for(int i=0;i<2000;i++){
		for(int j=0;j<2000;j++){
			int a = ((i%(2*d))<d);
			int b = ((j%(2*d))<d);
			
			if(a==0&&b==0)S[i][j]='R';
			else if(a==0&&b==1)S[i][j]='G';
			else if(a==1&&b==0)S[i][j]='Y';
			else S[i][j]='B';
		}
	}
	
	vector<string> ans(H,string(W,'.'));
	
	for(int i=0;i<H;i++){
		for(int j=0;j<W;j++){
			ans[i][j] = S[i-j+K][i+j+K];
		}
	}
	
	for(int i=0;i<H;i++)cout<<ans[i]<<endl;

	return 0;
}
