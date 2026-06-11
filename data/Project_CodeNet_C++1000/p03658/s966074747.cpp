#include <iostream>
#include <algorithm>
using namespace std;

int main(){
	int n,k;
	//if(scanf("%d %d", &n, &k)==EOF){return 0;}
	cin >> n >> k;
	vector<int> sticks(n);
	for(int i = 0; i < n ; i++){
		//if(scanf("%d", &l)==EOF){return 0;}
		cin >> sticks[i];
	}
	
	sort(sticks.begin(), sticks.end());
	int max = 0;
	for(int i = 0; i< k; i++){max += sticks[n-1-i];}	
	//printf("%d\n", max);
	cout << max << endl;
	return 0;

}