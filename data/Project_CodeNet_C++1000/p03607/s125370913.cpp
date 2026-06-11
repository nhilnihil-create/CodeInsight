#include <bits/stdc++.h>
using namespace std;

int main(void){
    int N;
    cin >> N;
    vector<int> A(N);
    
    
    for (int i = 0; i < N; i++)
    {
        cin >> A[i];
    }

    sort(A.begin(), A.end(), less<int>());

    vector<int> B(0);
    B.push_back(1);
    for(int i = 1; i < N; i++){
        if(A[i] == A[i-1]) {
            B[B.size()-1]++;
        } else {
            B.push_back(1);
        }
    }

    int cnt = 0;
    int bsize = B.size();
    for(int i = 0; i < bsize; i++){
        if(B[i] % 2 != 0) cnt++;
    }

    cout << cnt << endl;
    
    return 0;
}
