#include <iostream>

using namespace std;

int n;
int a[200005];
bool b[200005], stable[200005];

bool check(int x)
{
	for(int i = 1; i <= 2*n-1; i++) b[i] = (a[i] >= x);
	for(int i = 1; i <= 2*n-1; i++){
		stable[i] = (i-1 >= 1 && b[i-1] == b[i] || i+1 <= 2*n-1 && b[i+1] == b[i]); 
	}
	if(stable[n]) return b[n];
	
	for(int i = 1; i <= n-1; i++){
		if(stable[n-i] || stable[n+i]) return b[n-i];
	}
	if((n-1)%2) return !b[n];
	else return b[n];
}

int main(void)
{
	cin >> n;
	for(int i = 1; i <= 2*n-1; i++) cin >> a[i];
	
	int ub = 2*n, lb = 1, mid;
	while(ub-lb>1){
		mid = (ub+lb)/2;
		if(check(mid)) lb = mid;
		else ub = mid;
	}
	cout << lb << endl;
	
	return 0;
}