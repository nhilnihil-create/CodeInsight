#include <iostream>
using namespace std;
typedef long long ll;

int main(){
	int k,s;
	cin >> k >> s;

	int ans = 0;
	for(int x = 0;x <= k;x++){
		for(int y = 0;y <= k;y++){
			if(s - x - y <= k && s - x - y >= 0){
				ans++;
			}
		}
	}

	cout << ans << endl;
}
