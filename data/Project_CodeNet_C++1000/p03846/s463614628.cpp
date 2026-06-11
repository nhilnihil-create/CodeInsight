#include <bits/stdc++.h>

using namespace std;

bool isValid(int N, vector<int>& A){
    unordered_set<int> s(A.begin(), A.end());
    
    bool allOdd = all_of(s.begin(), s.end(), [](int i){ return i%2 != 0; });
    bool allEven = all_of(s.begin(), s.end(), [](int i){ return i%2 == 0; });

    return (s.size() == N/2 && N%2 == 0 && allOdd) ||
           (s.size() == N/2 + 1 && N%2 != 0 && allEven);
}

int modPow(int base, int power){
    int ans = 1;
    
    for(int i=0; i<power; i++){
        ans = (ans * base) % 1000000007;
    }

    return ans;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);


    int N;
    cin >> N;

    vector<int> A(N);
    int zeroes = 0;
    for(int i=0; i<N; i++){
        cin >> A[i];
        if(A[i] == 0){
            zeroes++;
        }
    }
    
    if(isValid(N, A) && zeroes <= 1) {
        cout << modPow(2, N/2) << "\n"; 
    }else{
        cout << 0 << "\n";
    }

    return 0;
}
