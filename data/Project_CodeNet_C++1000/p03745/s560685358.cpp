#include <bits/stdc++.h>
using namespace std;
 
int main() {
    int N;
    cin >> N;
    vector<int>A(N);
    for (int i = 0; i < N; i++) {
        cin >> A.at(i);
    }

    int count = 1;

    for (int i = 0; i < N; i++) {
        if (i != N-1){
            if (A.at(i) < A.at(i+1)){
                for (int j = 1; j < N-i-1; j++) {
                    if (A.at(i+j) > A.at(i+j+1)){
                        count++;
                        i += j;
                        break;
                    }
                    else if (j == N-i-2){
                        i += j;
                    }
                }
            }
            else if (A.at(i) > A.at(i+1)){
                for (int j = 1; j < N-i-1; j++) {
                    if (A.at(i+j) < A.at(i+j+1)){
                        count++;
                        i += j;
                        break;
                    }
                    else if (j == N-i-2){
                        i += j;
                    }
                }
            }
        }
    }
    cout << count << endl;
}