#include <iostream>
#include <map>
#include <vector>
#include <algorithm>
using namespace std;


long long f(vector<long long> a){
	int idx = max_element(a.begin(),a.end()) - a.begin();
	if( a[idx] < a.size() ) return 0;
	a[idx] -= a.size();
	a[idx^1] += 1;
	return 1 + f(a);
}

int main(){
	long long N;
	cin >> N;
	vector<long long> a(50,49 + N / 50);
	for(int i = 0 ; i < N % 50 ; i++){
		sort(a.begin(),a.end());
		a[0] += 50;
		for(int j = 1 ; j < 50 ; j++)
			a[j] -= 1;
	}
	cout << 50 << endl;
	for(int i = 0 ; i < 50 ; i++) cout << a[i] << (i + 1 == 50 ? "\n" : " ");
	// 4 4 4 4 | 4
	// 5 5 5 0 | 3
	// 1 6 6 1 | 2
	// 2 2 7 2 | 1
	// 3 3 3 3 | 0
	// 3 3 3 3  


}