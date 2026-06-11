#include <iostream>
#include <unordered_map>

using namespace std;

int main() {
	int n, a;
  	cin >> n;
  	unordered_map<int, bool> mp;
  	for (int i = 0; i < n; i++) {
    	cin >> a;
      	if (mp.find(a) != mp.end()) {
        	mp.erase(a);
        } else {
        	mp[a] = true;
        }
    }
  	cout << mp.size();
  	return 0;
}