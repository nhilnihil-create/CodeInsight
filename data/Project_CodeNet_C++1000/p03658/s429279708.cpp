#include<iostream>
#include<stdlib.h>
#include<math.h>
#include<algorithm>
#include<string.h>
using namespace std;

int main(){
	std::ios_base::sync_with_stdio(0);
	cin.tie(NULL); 
	int n,a[60],m,sum=0; cin >> n>>m;
	for (int i = 0; i <n; i++){
		cin >> a[i];
	}
	sort(a, a+n,greater<int>());
	for (int i = m-1; i >=0; i--){
		sum += a[i];
	}
	cout << sum << endl;
	return 0;
}


