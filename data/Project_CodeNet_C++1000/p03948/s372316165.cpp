#include <iostream>
#include <vector>
using namespace std;

long long N,T;
int main(){
	while(cin >> N >> T){
		vector<long long> large(N+10,0);
		vector<long long> small(N+10,0);		
		for(int i=0;i<N;i++){
			int a;
			cin >> a;
			large[i] = a;
			small[i] = a;
		}
		long long s = 10000000000;
		long long l = 0;
		for(int i=0;i<N;i++){
			if(s>small[i]){
				s = small[i];
				large[i] -= s;
			}else{
				small[i] = s;
				large[i] -= s;
			}
			if(large[i] > l){
				l = large[i];
			}
		}
		int count = 0;
		for(int i=0;i<N;i++){
			if(large[i] == l) count++; 
		}
		cout << count << endl;
	}
}