#include <iostream>
#include <algorithm>
using namespace std;
typedef long long lint;

lint a[7];
lint z0,z1;

int main(){
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	for(int i=0;i<7;i++){
		cin >> a[i];
	}


	z0 = (a[0]/2+a[3]/2+a[4]/2)*2ll;
	if(a[0]&&a[3]&&a[4]){
		a[0]--;
		a[3]--;
		a[4]--;
		z1 = (a[0]/2+a[3]/2+a[4]/2)*2ll + 3ll;
	}

	cout << a[1] + max(z0,z1) << endl;

	return 0;
}