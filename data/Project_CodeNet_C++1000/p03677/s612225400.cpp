#include <bits/stdc++.h>
#define rep(i,a,b) for(int i=int(a);i<int(b);++i)
#define SIZE 100005
#define INF 1000000005LL
#define MOD 1000000007

using namespace std;
typedef long long int ll;
typedef pair <int,int> P;

ll n,m;
ll A[SIZE*2],B[SIZE*2];
void imosu(ll l,ll r){
	if(l>r)return;
	A[l]++;
	A[r+1]--;
	B[r+1] += r+1-l;
}

int main()
{
	cin >> n >> m;
	ll a,b;
	cin >> b;
	ll X = 0;
	rep(i,1,n){
		a = b%m;
		cin >> b;
		if(b<a)b+=m;
		imosu(a+2,b);
		X += b-a;
	}
	rep(i,1,2*m+2){
		A[i] += A[i-1];
	}
	rep(i,1,2*m+2){
		A[i] -= B[i];
	}
	rep(i,1,2*m+2){
		A[i] += A[i-1];
	}
	ll Y = 0;
	rep(i,1,m+1){
		A[i] += A[i+m];
		Y = max(Y,A[i]);
	}

	//rep(i,1,m+1) cout << A[i] << endl;
	cout << X-Y << endl;

	return 0;
}
