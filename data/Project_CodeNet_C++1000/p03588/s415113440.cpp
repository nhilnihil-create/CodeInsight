#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const ll mod=1e9+7;

int main(){
    int N;
    cin >> N;
    vector<int> A(N), B(N);
    for(int i=0; i<N; i++){
        cin >> A[i] >> B[i];
    }
    int cnt=0;
    cnt+=*min_element(B.begin(), B.end());
    cnt+=*max_element(A.begin(), A.end());
    cout << cnt;
}