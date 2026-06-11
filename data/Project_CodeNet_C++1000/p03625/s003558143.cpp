#include <bits/stdc++.h>
using namespace std;
 
long long N, A[100100], kotak, kotak2;
 
int main() {
    cin >> N;
    for(int i=1; i<=N; i++) {
        cin >> A[i];
    }
    sort(A+1, A+N+1);
    for (int i=N; i>=2; i--){
        if(A[i]==A[i-1]){
            kotak=i;
            break;
        }
    }
    for (int i=kotak-2; i>=2; i--){
        if(A[i]==A[i-1]){
            kotak2=i;
            break;
        }
    }
    cout << A[kotak]*A[kotak2] << endl;
}