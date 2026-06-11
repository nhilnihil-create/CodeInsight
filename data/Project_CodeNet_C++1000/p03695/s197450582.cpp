#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define INF 1e9;
using namespace std;
using ll = long long;
vector <int> B(9);
int main() {
    int N;
    cin >> N;
    vector <int> A(N);
    for(int i = 0; i < N; i++){
        cin >> A[i];
        if(1 <= A[i] && A[i] < 400){
            B[0]++;
        }
        if(400 <= A[i] && A[i] < 800){
            B[1]++;
        }
        if(800 <= A[i] && A[i] < 1200){
            B[2]++;
        }
        if(1200 <= A[i] && A[i] < 1600){
            B[3]++;
        }
        if(1600 <= A[i] && A[i] < 2000){
            B[4]++;
        }
        if(2000 <= A[i] && A[i] < 2400){
            B[5]++;
        }
        if(2400 <= A[i] && A[i] < 2800){
            B[6]++;
        }
        if(2800 <= A[i] && A[i] < 3200){
            B[7]++;
        }
        if(3200 <= A[i]){
            B[8]++;
        }
    }
    int count = 0;
    for(int i = 0; i < 8; i++){
        if(B[i] != 0){
            count++;
        }
    }
    if(count == 0){
        cout << 1 << ' ' << B[8] << endl;
    }
    else{
        cout << count << ' ' << count + B[8] << endl;
    }
}
