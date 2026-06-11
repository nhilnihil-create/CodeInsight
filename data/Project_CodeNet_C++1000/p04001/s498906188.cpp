#include <bits/stdc++.h>
using namespace std;

int main(){
	string S;
	cin >> S;

	int N = S.size()*2-1;
	vector<char> ans(N);

	long long sum=0;
	long long sum2=0;
	for(int i=0; i < (1<<9); i++){
		bitset<9> ret(i);
		int cntS=0;
		sum2 += (int)S.at(cntS)-48;
		for(int j=0; j<(S.size()-1); j++){
			if(ret.test(j)){
				sum += sum2;
				cntS++;
				sum2 = (int)S.at(cntS)-48;
			}
			else{
				cntS++;
				sum2 *= 10;
				sum2 += (int)S.at(cntS)-48;
			}
		}
		sum += sum2;
		sum2 = 0;
		if( i == pow(2,S.size()-1)-1 ){
			cout << sum << endl;
			return 0;
		}
	}
}
