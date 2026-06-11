#include <bits/stdc++.h>
#define ALL(A) (A).begin(),(A).end()
#define ll long long
#define rep(i,n) for(int i=0;i<(n);i++)

const ll mod = 1e9+7;
const ll INF = -1*((1LL<<63)+1);
const int inf = -1*((1<<31)+1);

using namespace std;

int main(void){
	cin.tie(0);
	ios::sync_with_stdio(false);
	ll N,A,B,C,D;
	cin >> N >> A >> B >> C >> D;
	B-=A;
	A =0;
	//どの隣接する2マスについても整数の差はc以上d以下
	for(int i=0;i<N-1;i++){
		ll m = i;
		if(C*(N-1-m)-D*m <= B-A && B-A <= -C*m +(N-1-m)*D){
			cout << "YES" << endl;
			return 0;
		}
	}
	cout << "NO" << endl;
}