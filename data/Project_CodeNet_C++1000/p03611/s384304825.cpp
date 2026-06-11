 #include<bits/stdc++.h>
 
using namespace std;

const int N = 1e5 + 10; 

int q[N] , a[N]; //用数组hash

int main(){
	
	int n;
	cin >> n;
	for(int i = 0 ; i < n ; i ++) cin >> a[i];
	
	for(int i = 0 ; i < n ; i ++)
		q[a[i] - 1]++ , q[a[i]]++ , q[a[i] + 1]++; // 记录三种操作数出现的次数
	
	int maxn = 0;
	for(int i = 1 ; i < N ; i ++) maxn = max(maxn , q[i]); // 求最大
	
	cout << maxn << endl;
	return 0;
}