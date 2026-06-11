#include<cstdio>
#include<cstring>
#include<vector>
#include<queue>
#include<stack>
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
ll MOD = 1e9+7;
//LLONG_MIN

/*
問題の見かけに反して重実装

アリとラベルを別に考える。
アリ同士がぶつかる際に、すり抜けてラベルだけ交換するとしても同じ
アリ0がA回ぶつかったらラベルは
	アリ0が右回りなら：(0+A)%n
	アリ0が左回りなら：(0-A)%n
ラベルの順序は変わらないので、アリ0が何回ぶつかるかをカウントすれば全てのアリのラベルと位置が分かる
ただし、アリ0と同じ位置のが2個あったら、ソートする際にアリ0がどの位置に置かれるかが不明なため、個別に考える
	右回りの場合は：２つのうち中心から見て左側
	左回りの場合は：２つのうち中心から見て右側

速度を半分にして時間を倍にすると端数が出なくて計算しやすい
*/

bool is_same_pos=false;
ll n,l,t,x[100010],w[100010],hit=0,zero_id,zero_pos,ans[100010];
mp afterPos_and_beforeID[100010];

int main(void){
	cin>>n>>l>>t;
	rep(i,n)cin>>x[i]>>w[i];
	//アリ0がぶつかる回数をカウント
	rep(i,n){
		if(w[0]==1 && w[i]==2){//回転方向によってカウント方法が変わるので
			if(2*t-(x[i]-x[0])>0){//ちょうどは衝突に含めない
				hit++;
				if((2*t-(x[i]-x[0]))%l==0){//ちょうどは衝突に含めない
					hit+=(2*t-(x[i]-x[0]))/l - 1;
				}else{
					hit+=(2*t-(x[i]-x[0]))/l;
				}
			}
		}
		if(w[0]==2 && w[i]==1){
			if(2*t-(l-(x[i]-x[0]))>0){
				hit++;
				if((2*t-(l-(x[i]-x[0])))%l==0){//ちょうどは衝突に含めない
					hit+=(2*t-(l-(x[i]-x[0])))/l - 1;
				}else{
					hit+=(2*t-(l-(x[i]-x[0])))/l;
				}
			}
		}
	}
	//t秒後のアリの位置
	rep(i,n){
		if(w[i]==1){
			x[i]=(x[i]+t)%l;
		}else{
			x[i]=((x[i]-t)%l+l)%l;
		}
		if(i==0){
			zero_pos=x[i];
		}else if(x[0]==x[i]){//同じ位置のやつがいるか確認
			is_same_pos=true;
		}
	}
	sort(x,x+n);
	//アリ0がどこに行ったか調べる
	rep(i,n){
		if(x[i]==zero_pos){
			if(is_same_pos){
				if(w[0]==1){
					//右に同じ位置のがあるか確認
					if(x[(i+1)%n]==x[i]){
						zero_id=i;
					}else{
						zero_id=(i-1+n)%n;
					}
				}else{
					//左に同じ位置のがあるか確認
					if(x[(i-1+n)%n]==x[i]){
						zero_id=i;
					}else{
						zero_id=(i+1)%n;
					}
				}
			}else{
				zero_id=i;
				break;
			}
		}
	}
	//ラベルの付替え作業
	rep(i,n){
		int after_id;
		if(w[0]==1){//進む方向によってアリ0のラベルの値が変わるので
			after_id = ((i-zero_id+hit)%n+n)%n;
		}else{
			after_id = ((i-zero_id-hit)%n+n)%n;
		}
		ans[after_id] = x[i];
	}
	rep(i,n)cout<<ans[i]<<endl;
	return 0;
}