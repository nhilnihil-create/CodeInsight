#include <bits/stdc++.h>
#define rep(i,a,b) for(int i=int(a);i<int(b);++i)
#define SIZE 100005
#define INF 1000000005LL
#define MOD 1000000007

using namespace std;
typedef long long int ll;
typedef pair <ll,int> P;

int N;
ll A[SIZE],B[SIZE],sB[SIZE*2];
P T[SIZE*2]; //ソート後の位置計算用
int U[SIZE*2]; //ソート後の位置
bool W[SIZE*2]; //消えたかどうか
ll a;

int main()
{
	cin >> N;
	priority_queue<ll,vector<ll>,greater<ll>> que;
	ll asum = 0;
	rep(i,0,N){
		cin >> a;
		que.push(a);
		asum += a;
	}
	rep(i,0,N){
		cin >> A[i];
		sB[i] = A[i];
		T[i] = P(sB[i],i);
	}
	ll bsum=0;
	rep(i,0,N){
		cin >> B[i];
		sB[i+N] = B[i];
		T[i+N] = P(sB[i+N],i+N);
	}
	sort(sB,sB+2*N);
	sort(T,T+2*N); //ソート後の位置計算用
	rep(i,0,2*N) { //ソート後の位置
		U[T[i].second] = i;
	}

	rep(i,0,N) bsum += sB[i];
	int bmin = N-1;
	ll ans = asum - bsum;
	rep(i,0,N) {
		asum += A[i];
		que.push(A[i]);
		asum -= que.top();que.pop();

		if(A[i] <= sB[bmin]){ //消える
			W[U[i]] = true;
			bmin++;
			while(W[bmin])bmin++;
			bsum -= A[i];
			bsum += sB[bmin];
		}else{ //変わらない
			W[U[i]] = true;
		}
		//cout << asum << " " << bsum << endl;

		ans = max(ans,asum-bsum);
	}


	cout << ans << endl;
	
	return 0;
}
