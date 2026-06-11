#include <bits/stdc++.h>
using namespace std;

int main() {
	string S;
	cin >> S;
	int N = S.size();
	vector<bitset<10>> v;

	for(int tmp=0;tmp < (1 << (N - 1));tmp++){
		bitset<10> bits(tmp);
		v.push_back(bits);
	}

	long long ans=0;
	string tmp;

	for(int i=0;i<(1 << (N - 1));i++){
		for(int j=0; j<N; j++){
			tmp.push_back(S.at(j));
			if(v.at(i).test(j)){
				ans += stoll(tmp);
				tmp = "";
			}
		}
		if(!(tmp == "")){
			ans += stoll(tmp);
			tmp = "";
		}
	}

	cout << ans << endl;
}
