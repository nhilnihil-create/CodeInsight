#include<iostream>
#include<vector>
#include<string>
#include<map>
#include<algorithm>
#include<cmath>
using namespace std;

typedef long long int llint;

int main(){
	llint A,B,C;
	cin >> A >> B >> C;
	if( A%2==0 || B%2==0 || C%2==0 ){
		cout << 0 << endl;
	}else{
		vector<llint> v={A*B,B*C,C*A};
		cout << *min_element(v.begin(),v.end()) << endl;
	}
	return 0;
}
