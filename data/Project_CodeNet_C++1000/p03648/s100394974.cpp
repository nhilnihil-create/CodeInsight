#include <iostream>
#include <string>
#include <utility>
#include <vector>
#include <algorithm>
#define llint long long 
#define mod 1000000007

using namespace std;
typedef pair<llint, llint> P;

llint k;
llint ans[55];

int main(void)
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	cin >> k;
	for(int i = 0; i < 50; i++) ans[i] = (k+49)/50 + i;
	if(k % 50){
		for(int i = 0; i < 50-(k%50); i++) ans[i]--;
	}
	cout << 50 << endl;
	for(int i = 0; i < 50; i++) cout << ans[i] << " "; cout << endl;
	
	return 0;
}