#include <bits/stdc++.h>
using namespace std;
#define mod 1000000007
int main(){
	int n;
	int x[100100];
	long long ans = 1;
	scanf("%d",&n);
	for (int i = 0; i < n; ++i)
	{
		scanf("%d",&x[i]);
	}
	//一個でもゴールできないものができると
	//その後ろは全員ゴールできない

	//ロボットのとりうる最高順位をkとする
	//ロボットは自分より前にいるロボットの最高順位kを超えることはできない。

	//ロボットの取りうる最高順位は変化するか？->変化しない
	
	//ゴールできる=マップ上のロボットがWの距離までにW/2+1個以下しかない
	//後ろのやつがゴールした後の状態だとそれより前のやつは全員ゴールできる

	//それぞれのロボットに関して最高順位kを求める


	int tmpk = 1;
	for (int i = 0; i < n; ++i)
	{
		//iは自分より前にいるロボットの個数
		ans *= tmpk;
		ans %= mod;
		//ロボットが抜かせれる個数tmpkとする
		if(x[i]>(tmpk-1)*2){
		  tmpk++;
		  //とれる最高順位 i-tmpk
		}
	}
	cout << ans << endl;
	return 0;
}