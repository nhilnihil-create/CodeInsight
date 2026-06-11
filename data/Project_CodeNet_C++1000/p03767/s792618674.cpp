#include<iostream>
#include<vector>
#include<string>
#include<map>
#include<algorithm>
#include<cmath>
using namespace std;

typedef long long int llint;

int main(){
	int N;
	cin >> N;
	vector<llint> A;
	for(int i=0;i<3*N;i++){
		llint a;
		cin >> a;
		A.push_back(a);
	}
	sort(A.rbegin(),A.rend());
	llint sum=0;
	auto it=A.begin();
	for(int i=0;i<N;i++){
		it++;
		sum+=*it;
		it++;
	}

	cout << sum << endl;
	return 0;
}
