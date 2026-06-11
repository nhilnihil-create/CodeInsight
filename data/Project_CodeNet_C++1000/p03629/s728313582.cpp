#include<cstdio>
#include<cstring>
#include<vector>
#include<queue>
#include<algorithm>
#include<cmath>
#include<climits>
#include<string>
#include<set>
#include<numeric>
#include<map>
#include<iostream>
using namespace std;
#define rep(i,n) for(int i = 0;i<((int)(n));i++)
#define reg(i,a,b) for(int i = ((int)(a));i<=((int)(b));i++)
#define irep(i,n) for(int i = ((int)(n)-1);i>=0;i--)
#define ireg(i,a,b) for(int i = ((int)(b));i>=((int)(a));i--)
typedef long long ll;
typedef pair<ll, ll> mp;

/*
ac
含まれない部分文字列の最後の文字をαに固定する．
すると，最後に出てきたαよりも前の文字列の中に含まれない最短部分文字列を求める問題に帰着された．
順番に気をつけよう（1敗）（右から左へのdpでないと辞書順にならない）
*/

int dp[200010]={},before[200010][26];
string a;

int f(int i){
	if(i>a.size())return 0;
	if(dp[i]!=0)return dp[i];
	int smallest=1e9;
	rep(j,26){
		smallest=min(smallest,f(before[i][j]+1));//最後がj種類目のアルファベットで終わる最短文字列
	}
	return dp[i]=smallest+1;
}

string g(int i){
	if(i>a.size())return "";
	rep(j,26){
		if(f(before[i][j]+1)+1==dp[i])return (char)('a'+j)+g(before[i][j]+1);
	}
	return "ああああああ！！！！！！！！！";
}

int main(void){
	cin>>a;
	rep(j,26)before[a.size()][j]=a.size();//まだ出てない文字
	dp[a.size()]=1;//空文字列に含まれない最短部分列の長さは1（1敗）
	irep(i,a.size()){
		rep(j,26)before[i][j]=before[i+1][j];
		before[i][a[i]-'a']=i;
	}
	f(0);
	cout<<g(0)<<endl;
	return 0;
}