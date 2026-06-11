#define _CRT_SECURE_NO_WARNINGS
#define _USE_MATH_DEFINES
#include <iostream>
#include <iomanip>
#include <cstdio>
#include <cstring>
#include <cmath>
#include <cstdlib>
#include <algorithm>
#include <string>
#include <vector>
#include <stack>
#include <queue>
#include <set>
#include <map>
#include <unordered_map>
#include <functional>
#include <utility>
#include <tuple>
#include <cctype>
#include <bitset>
#include <complex>
#include <cmath>
#include <array>
using namespace std;
#define INF 0x3f3f3f3f
#define INFLL 0x3f3f3f3f3f3f3f3fLL
#define MOD 1000000007
#define mp make_pair
#define mt make_tuple
#define pb push_back
#define eb emplace_back
typedef long long ll;
typedef long double ld;
typedef pair<int, int> pint;
typedef pair<ll,ll> pll;
typedef tuple<int,int,int> tint;
typedef vector<int> vint;
typedef vector<ll> vll;
typedef vector<pint> vpint;
int dx[8]={0,0,-1,1,1,1,-1,-1};
int dy[8]={-1,1,0,0,1,-1,1,-1};
const int SIZE=100050;
//ここまでテンプレ
//↓区間和を求めるSegmentTree
struct SegmentTreeSum {
private:
    ll n;
    vector<ll> node;

public:
    // 元配列 v をセグメント木で表現する
    SegmentTreeSum(vector<ll> v) {
        // 最下段のノード数は元配列のサイズ以上になる最小の 2 冪 -> これを n とおく
        // セグメント木全体で必要なノード数は 2n-1 個である
        ll sz = v.size();
        n = 1; while(n < sz) n *= 2;
        node.resize(2*n-1, 0);

        // 最下段に値を入れたあとに、下の段から順番に値を入れる
        // 値を入れるには、自分の子の 2 値を参照すれば良い
        for(ll i=0; i<sz; i++) node[i+n-1] = v[i];
        for(ll i=n-2; i>=0; i--) node[i] = (node[2*i+1] + node[2*i+2]);
    }
	void update(ll x, ll val) {
		// 最下段のノードにアクセスする
		x += (n - 1);

		// 最下段のノードを更新したら、あとは親に上って更新していく
		node[x] = val;
		while(x > 0) {
			x = (x - 1) / 2;
			node[x] = (node[2*x+1] + node[2*x+2]);
		}
	}
	ll getsum(ll a, ll b, ll k=0, ll l=0, ll r=-1) {
		// 最初に呼び出されたときの対象区間は [0, n)
		if(r < 0) r = n;

		// 要求区間と対象区間が交わらない -> 適当に返す
		if(r <= a || b <= l) return 0;

		// 要求区間が対象区間を完全に被覆 -> 対象区間を答えの計算に使う
		if(a <= l && r <= b) return node[k];

		// 要求区間が対象区間の一部を被覆 -> 子について探索を行う
		// 左側の子を vl ・ 右側の子を vr としている
		// 新しい対象区間は、現在の対象区間を半分に割ったもの
		ll vl = getsum(a, b, 2*k+1, l, (l+r)/2);
		ll vr = getsum(a, b, 2*k+2, (l+r)/2, r);
		return (vl + vr);
	}
};
//↑区間和を求めるSegmentTree
int main(){
	ll N;
	cin>>N;
	vector<tuple<ll,ll,ll>> A,B;
	ll maxi=0;
	for(int i=0;i<N;i++){
		ll a;
		cin>>a;
		A.eb(a,i,(a>maxi));
		maxi=max(maxi,a);
	}
	B=A;
	/*
	for(int i=0;i<N;i++){
		ll a,b,c;
		tie(a,b,c)=A[i];
		cout<<a<<" "<<b<<" "<<c<<endl;
	}
	*/
	sort(A.begin(),A.end());
	vll node;
	for(ll i=0;i<N;i++)
		node.pb(get<0>(A[i]));
	SegmentTreeSum S(node);
	ll ans[SIZE]={};
	ll wa[SIZE]={};
	//flagが立ってるやつの番号
	vint F;
	for(int i=0;i<N;i++)
		if(get<2>(A[i]))
			F.pb(i);
	ans[get<1>(A[F[0]])]=S.getsum(0,N);
	for(int i=0;i<F.size()-1;i++){
		ll a,b,c;
		tie(a,b,c)=A[F[i]];
		ans[get<1>(A[F[i+1]])]=S.getsum(F[i],N)-a*(N-F[i]);
	}
	/*
	for(int i=0;i<N;i++)
		if(!get<2>(B[i]))
			ans[i]=0;
	*/
	ll prev=0;
	for(int i=N-1;i>=0;i--){
		if(ans[i]!=0){
			ll temp=prev;
			prev=ans[i];
			ans[i]-=temp;
		}
	}
	for(ll i=0;i<N;i++)
		cout<<ans[i]<<endl;
	return 0;
}