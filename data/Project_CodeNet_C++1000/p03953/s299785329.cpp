#include <iostream>
#include <vector>
#include <stdio.h>
#define llint long long

using namespace std;

llint N;
llint x[100005];
llint dif[100005];
llint M, K;
llint a[100005];
vector<llint> perm(100005), ans(100005), iden(100005);

vector<llint> pow(vector<llint> p, llint n)
{
	vector<llint> tmp(N), tmp2(N);
	
	if(n == 0) return iden;
	if(n % 2){
		tmp = pow(p, n-1);
		for(int i = 1; i <= N-1; i++) tmp2[i] = p[tmp[i]];
		return tmp2;
	}
	else{
		for(int i = 1; i <= N-1; i++) tmp[i] = p[p[i]];
		return pow(tmp, n/2);
	}
}

int main(void)
{
	cin >> N;
	for(int i = 1; i <= N; i++) cin >> x[i];
	for(int i = 1; i <= N-1; i++) dif[i] = x[i+1] - x[i];
	cin >> M >> K;
	for(int i = 1; i <= M; i++) cin >> a[i];
	
	for(int i = 1; i <= N-1; i++){
		perm[i] = i;
		iden[i] = i;
	}
	for(int i = 1; i <= M; i++){
		llint t = perm[a[i]];
		perm[a[i]] = perm[a[i]-1];
		perm[a[i]-1] = t;
	}
	
	ans = pow(perm, K);
	
	llint prev = x[1];
	cout << prev << endl;
	
	for(int i = 1; i <= N-1; i++){
		prev += dif[ans[i]];
		printf("%.11f\n", (double)prev);
	}
	
	return 0;
}