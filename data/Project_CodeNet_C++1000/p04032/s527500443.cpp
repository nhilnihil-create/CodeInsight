#include <iostream>
#include <algorithm>
using namespace std;

int main() {
	string ss;
	cin >> ss;
	/*string xx = ss;
	sort(xx.begin(), xx.end());
	int count = 0;
	for (int i=0; i<=xx.length()/2; i++){
		if (xx[i]==xx[i+1]){
			count ++;
		}
	}
	if (count<=xx.length()/2){
		cout << -1 << ' ' << "-1\n";
		return 0;
	} */
	
	
	
	for (int i=0; i<ss.length()-1; i++){
		if (ss[i]==ss[i+1]){
			cout << i+1 << ' ' << i+2 << endl;
			return 0;
		}
	}
	for (int i=0; i<ss.length()-2; i++){
		if (ss[i]==ss[i+2]){
			cout << i+1 << ' ' << i+3 << endl;
			return 0;
		}
	}
	cout << -1 << ' ' << -1 << endl;
}