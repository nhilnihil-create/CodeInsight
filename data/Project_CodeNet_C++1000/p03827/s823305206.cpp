#include <iostream>
#include <algorithm>
using namespace std;

int main() {
ios_base::sync_with_stdio(0); cin.tie(0); 
int n;
cin >> n;
string s;
cin >> s;
int temp{};
int ans{};
for(int i{}; i<n; i++){
	if(s[i] == 'I'){
		++temp;
	}else if(s[i] == 'D'){
		--temp;
	}

ans = max(ans,temp);
}
	cout << ans << "\n";
	return 0;
}
