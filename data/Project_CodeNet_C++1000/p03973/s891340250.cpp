#include <iostream>
#define llint long long 

using namespace std;

llint N;
llint A[100005];

int main(void)
{
	cin >> N;
	for(int i = 0; i < N; i++) cin >> A[i];
	
	llint ans = 0;
	llint val = 1;
	for(int i = 0; i < N; i++){
		if(A[i] < val) continue;
		if(A[i] == val) val++;
		else ans += (A[i] - 1) / val;
		if(val == 1) val = 2;
	}
	
	cout << ans << endl;
	return 0;
}