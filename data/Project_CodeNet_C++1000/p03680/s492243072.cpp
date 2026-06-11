#define _GLIBCXX_DEBUG
#include <bits/stdc++.h>
using namespace std;

int main() {
  	int N;
    cin >> N;
    vector<int> A(N);
    for (int i=0; i<N; i++){
    	cin >> A[i];
    }
  	vector<bool> B(N,0);
    B[0] = 1;
    int x = A[0];
    int count = 0;
    while(true){
    	if (B[x-1] == 0){
        	B[x-1] = 1;
            count++;
            x = A[x-1];
        }
        else if (B[x-1] == 1){
        	cout << -1 << endl;
          	break;
        }
        if (B[1] == 1){
        	cout << count << endl;
            break;
        }
    }
} 