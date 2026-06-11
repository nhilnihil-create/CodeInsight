#include <bits/stdc++.h>
using namespace std;

template<typename T>
vector<T> compress(vector<T> A){
    sort(A.begin(), A.end());
    A.erase(unique(A.begin(), A.end()), A.end());
    return A;
}

int main(){
    int N;
    cin >> N;
    vector<pair<int, int>> A(N);
    for(int i=0; i<N; i++){
        int a;
        cin >> a;
        A[i] = {a, i};
    }
    sort(A.begin(), A.end());
    int ans = 0;
    for(int i=0; i<N; i++) if((i-A[i].second)%2) ans++;
    ans /= 2;
    cout << ans << endl;
}