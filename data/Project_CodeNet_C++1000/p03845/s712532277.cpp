#include<iostream>
using namespace std;

const int maxn = 103;

int main(){
	int n, m ,t[maxn], x[maxn], p[maxn];
	cin >> n;
	for(int i = 1; i<=n; i++){
		cin >> t[i];
	} 
	
	int sum = 0;
	for(int i = 1; i<=n ;i++){
		sum += t[i];
	}
	
	
	cin >> m;
	for(int i = 1; i<=m ;i++){
		cin >> p[i] >> x[i];
		int tmp = sum;
		tmp -= t[p[i]];
		tmp += x[i];
		cout << tmp << endl;
	}
	return 0;
}  