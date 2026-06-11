#define _GLIBCXX_DEBUG
#include <bits/stdc++.h>
using namespace std;

int main() {
  		int N, M;
  		cin >> N >> M;
  		vector<int> Ans(N,0);
  		vector<int> road(2*M);
        for (int i=0; i<2*M; i++){
          		cin >> road[i];
        }
  	 	for (int i=0; i<2*M; i++){
          		Ans[road[i]-1]++;
        }
  		for (int i=0; i<N; i++){
          		cout << Ans[i] << endl;
        }
}
