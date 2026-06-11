#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define rep(i,n) for(ll i = 0;i<((ll)(n));i++)
#define reg(i,a,b) for(ll i = ((ll)(a));i<=((ll)(b));i++)
#define irep(i,n) for(ll i = ((ll)(n)-1);i>=0;i--)
#define ireg(i,a,b) for(ll i = ((ll)(b));i>=((ll)(a));i--)
template<class T = int> using V = vector<T>;
template<class T = int> using VV = V< V<T> >;

/*
*/

ll n,L,x[100010],d[100010][18],Q;

void init(){
	cin>>n;
	rep(i,n)cin>>x[i];
	cin>>L>>Q;
}

int main(void){
	init();
	// sparce tableの構築
	int curpos=0;  // 今の位置
	rep(i,n){  // 尺取り法でやる
		while(x[curpos+1]-x[i]<=L && curpos+1<n)curpos++;
		d[i][0]=curpos;
	}
	reg(j,1,17)rep(i,n)d[i][j] = d[d[i][j-1]][j-1];
	// rep(i,n){
	// 	cerr<<i<<": ";
	// 	reg(j,0,17)cerr<<d[i][j]<<" ";
	// 	cerr<<endl;
	// }
	// query処理
	rep(i,Q){
		ll a,b,ans=0;
		cin>>a>>b;
		a--;
		b--;
		if(a>b)swap(a,b);
		int cpos=a;  // 今の位置
		irep(j,18){
			if(cpos>=b)break;
			if(d[cpos][j]<b){
				cpos = d[cpos][j];
				ans += 1<<j;
			}
			if(j==0 && cpos<b){
				cpos = d[cpos][0];
				ans++;
			}
		}
		if(cpos<b)cerr<<"ダメ"<<endl;
		cout<<ans<<endl;
	}
	return 0;
}