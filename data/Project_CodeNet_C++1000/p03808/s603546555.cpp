#include <bits/stdc++.h>
using namespace std;

void die(){
	cout << "NO";
	exit(0);
}
long long arr[100005];
int main(){
	//freopen("i.txt","r",stdin);
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	
	long long n; cin >> n;
	long long T = (n) * (n + 1) / 2;
	
	
	long long total = 0;
	for(int i = 0;i < n;i++){
		cin >> arr[i];
		total += arr[i];
	}
	arr[n] = arr[0];
	
	if(total % T != 0) die();
	
	long long E = total / T;
	
	long long match = 0;
	for(int i = 0;i < n;i++){
		long long diff = arr[i+1] - arr[i];
		
		if(diff > E) die();
		if((E - diff) % n != 0) die();
		
		long long need = (E - diff) / n;
		match += need;
	}
	
	if(match != E) die();
	cout << "YES";
}
