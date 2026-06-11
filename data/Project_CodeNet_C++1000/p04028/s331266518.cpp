/*

IDE: DP

DP bisa dikerjakan dari belakang, jadi dari string S kita mencari banyaknya cara membuatnya menjadi string kosong.

Kita punya 2 tipe operasi:
- menghapus karakter terakhir dari S
- menambahkan karakter 0 atau 1 dari S
- tidak melakukan apa-apa (apabila string kosong)

Jadi, DPnya DP[len][k]: banyaknya cara membuat string kosong, dengan panjang sekarang len dan bisa melakukan s operasi lagi.
*/
#include <bits/stdc++.h>
using namespace std;
#define MOD 1000000007
#define MAXN 5000

int dp[MAXN+1][MAXN+1];

int solve(int len, int sis) {
	if(len>MAXN || len<0)	return 0;
	if(sis==0)
		return (len==0);

	int &ans = dp[len][sis];
	if(ans!=-1)	return ans;


	// append
	ans = solve(len-1, sis-1);

	//backspace
	ans+= 2*solve(len+1, sis-1)%MOD;

	if(ans>=MOD)
		ans-=MOD;

	// do nothing
	if(len==0)	ans+=solve(len, sis-1);

	if(ans>=MOD)
		ans-=MOD;


	//cout<<len<<" "<<sis<<" "<<dp[len][sis]<<"\n";
	return ans;
}
int main() {
	ios_base::sync_with_stdio(false);
	memset(dp,-1,sizeof(dp));
	int n;
	string s;
	cin>>n>>s;
	cout<<solve(s.size(), n)<<"\n";

}