#include <iostream>
#include <string>
#include <utility>
#include <stack>
#include <vector>
#include <queue>
#include <algorithm>
#include <map>
#include <climits>
#include <set>
#include <cmath>
#include <numeric>
using namespace std;

long long A[100000];
long long diff_A[100000];
long long x[100000];
long long y[100000];
int main(){
    int N;
    cin >> N;

    for(int i = 0; i < N; i++){
        cin >> A[i];
    }

    for(int i = 0; i < N; i++){
        diff_A[i] = A[(i + 1) % N] - A[i];
    }
    long long sum_A = accumulate(A, A + N, (long long) 0);
    long long sum_N = (long long) N * (long long)(N + 1) / 2;

    if((sum_A % sum_N) != 0){
        cout << "NO" << endl;
        return 0;
    }
    long long op_num = sum_A / sum_N;

    for(int i = 0; i < N; i++){
        if((op_num - diff_A[i]) < 0 || (op_num - diff_A[i]) % N != 0){
            cout << "NO" << endl;
            return 0;
        }
        y[i] = (op_num - diff_A[i]) / N;
        x[i] = op_num - y[i];
    }

    long long A0 = 0;
    for(int i = 0; i < N; i++){
        A0 += (N - i) * y[i];
    }
    if(A0 == A[0]){
        cout << "YES" << endl;
    } else {
        cout << "NO" << endl;
    }
    return 0;
}
