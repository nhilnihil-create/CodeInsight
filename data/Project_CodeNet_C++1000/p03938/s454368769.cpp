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
	int N;
    cin >> N;
    vector<int> p(N);
    rep(i,N){
        cin >> p[i];
        p[i]--;
    }
    static const int Max = 40010;
    vector<int> A(N),B(N);
    rep(i,N){
        A[i] = B[N-1-i] = Max * i + 1;
    }
    rep(i,N){
        A[p[i]] += i;
    }
    rep(i,N)cout << A[i] << endl;
    rep(i,N)cout << B[i] << endl;
}