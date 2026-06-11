#include<bits/stdc++.h>

using namespace std;

int N, A[100000];
vector<int> es;

int main(){
	cin >> N;
	for(int i = 0; i < N; ++i) cin >> A[i];
	sort(A, A + N);
	
	for(int i = 0; i < N - 1; ++i){
		if(A[i] == A[i+1]){
			es.push_back(A[i]);
			++i;
		}
	}
	
	if(es.size() >= 2){
		cout << 1LL*es[es.size()-2]*es[es.size()-1] << endl;
	}else{
		cout << 0 << endl;
	}
}