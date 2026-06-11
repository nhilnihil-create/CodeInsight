#include<bits/stdc++.h>
using namespace std;

long long N;

#define BAK 1
#define FRONT 2

int main(){
	cin >> N;

	deque<long long> dq;
	for(long long i = 0; i < 100 && N; i++){
		//cout << "N = " << N << endl;
		if((N - 1)%2 == 0){
			//cout << "bak" << endl;
			N = (N-1)/2;
			dq.push_front(BAK);
		}else{
			//cout << "fron" << endl;
			N--;
			dq.push_front(FRONT);
		}
	}

	deque<long long> ansdq;

	for(long long i = 0; i < dq.size(); i++){
		if(dq[i] == BAK){
			ansdq.push_back(i+1);
		}else{
			ansdq.push_front(i+1);
		}
	}


	cout << 2 * dq.size() << endl;
	for(long long i = 1; i <= dq.size(); i++){
		cout << i << " ";
	}

	for(long long i = 0; i < dq.size(); i++){
		cout << ansdq[i];
		if(i != ansdq.size() - 1){
			cout << " ";
		}
	}
	cout << endl;
}

