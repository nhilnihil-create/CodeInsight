#include <iostream>
#include <vector>
#include <algorithm>
#include <set>
using namespace std;
int gcd(int x, int y){
    if(x < y) swap(x, y);
    if(x % y == 0) return y;
    return gcd(y, x % y);
}
int main(){
    long long N, K;
    cin >> N >> K;
    vector<long long> A(N);
    for(int i = 0; i < N; i++) cin >> A[i];
    sort(A.begin(), A.end());
    for(int i = 0; i < N; i++){
        if(A[i] == K){
            cout << "POSSIBLE" << endl;
            return 0;
        }
    }
    if(K > A[N - 1]){
        cout << "IMPOSSIBLE" << endl;
        return 0;
    }
    set<int> s;
    for(int i = 0; i < N - 1; i++){
        s.insert(gcd(A[i], A[i + 1]));
    }
    for(int i = 0; i < N; i++){
        if(s.count(gcd(K, A[i]))){
            cout << "POSSIBLE" << endl;
            return 0;
        }
    }
    cout << "IMPOSSIBLE" << endl;
}