#include<iostream>
using namespace std;

const int maxn = 103;

int main(){
	int n, m ,t[maxn], x, p;
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
		cin >> p >> x;
		int tmp = sum;
		tmp -= t[p];
		tmp += x;
		cout << tmp << endl;
	}
	return 0;
}  