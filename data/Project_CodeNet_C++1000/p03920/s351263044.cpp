#include <iostream>
#include <vector>

using namespace std;

int main(){
	int N;
	while(cin >> N){
		int e = 0;
		while(e*(e+1)/2 < N) ++e;
		vector<int> r;
		for(int i=e;i>=1;i--){
			if(N >= i){
				r.push_back(i);
				N -= i;
			}
		}
		for(auto it=r.rbegin();it!=r.rend();++it) cout << *it << endl;
	}
}
