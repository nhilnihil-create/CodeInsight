#include <bits/stdc++.h>
#include <algorithm>
using namespace std;
int main(void){
    
    int N;
    cin >> N;
    long long A[N];
    long long B[N];
    for(int i = 0; i <N;i++)cin >> A[i] >> B[i];
    
    long long max = 0;
    int num;
    for(int i = 0; i < N;i++){
        if(max < A[i]){
            max = A[i];
            num = i;
            //cout << max <<" "<< num << endl;
        }
    }
    //cout << max <<endl;
    //cout << num <<endl;
    cout << max + B[num] <<endl;
    
}
