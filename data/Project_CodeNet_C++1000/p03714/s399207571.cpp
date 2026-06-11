#include<cstdio>
#include<cstring>
#include<cstdlib>
#include<cmath>
#include<iostream>
#include<algorithm>
#include<queue>
#include<vector>
using namespace std;

const int MaxN = 3e5;
typedef long long LL;
typedef unsigned long long ULL;

LL ans,n,sum;
LL f[MaxN + 5],e[MaxN + 5],a[MaxN + 5];

priority_queue<LL>q2;
priority_queue<LL,vector<LL>,greater<LL> >q1;

int main(){
	ans = -(1LL << 60);
	cin >> n;
	for(int i = 1;i <= 3*n;i++){
		cin >>a[i];
	}
	for(int i = 1;i <= 3*n;i++){
		q1.push(a[i]);
		sum += a[i];
		f[i] = sum;
		if(q1.size() > n){
			sum -= q1.top();
			f[i] = sum;
			q1.pop();
		}
	}
	sum = 0;
	for(int i = 3*n;i >= 1;i--){
		q2.push(a[i]);
		sum += a[i];
		e[i] = sum;
		if(q2.size() > n){
			sum -= q2.top();
			e[i] = sum;
			q2.pop();
		}
	}
	for(int i = n;i <= n*2;i++){
		ans = max(ans,f[i] - e[i + 1]);
	}
	cout << ans << endl;
}