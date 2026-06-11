#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <math.h>
using namespace std;
typedef long long int ll;

int main(){
	int n; cin >> n;
	vector<int> a(n),b(n);
	for(int i=0;i<n;i++){
		cin >> a[i] >> b[i] ; 
	}
	sort(a.begin(),a.end());
	sort(b.begin(),b.end());
	cout << a[n-1]+(b[0]-0) << endl;
}