#include <bits/stdc++.h>
using namespace std;
int main(void){
    int N;
    cin >> N;
    vector<int> A(N);
    for(int i = 0; i < N; i++) cin >> A[i];
    sort(A.begin(),A.end());
    map<int,int> mp;
    for(int i = 0; i < N; i++) mp[A[i]]++;
    long long ans = 1;
    if(N == 1){
        cout << 1 << endl;
    }
    else if(N%2 == 1){
        if(A[0] != 0 || A[1] == 0){
            cout << 0 << endl;
            return 0;
        }
        for(int i = 1; i < N-2; i += 2){
            if(A[i] != A[i+1] || A[i+1] == A[i+2]){
                cout << 0 << endl;
                return 0;
            }
            if(A[i]%2 != 0){
                cout << 0 << endl;
                return 0;
            }
        }
        for(int i = 0; i < mp.size()-1; i++){
            ans *= 2;
            ans %= 1000000007;
        }
        cout << ans << endl;
    }
    else{
        for(int i = 0; i < N-2; i += 2){
            if(A[i] != A[i+1] || A[i+1] == A[i+2]){
                cout << 0 << endl;
                return 0;
            }
            if(A[i]%2 != 1){
                cout << 0 << endl;
                return 0;
            }
        }
        for(int i = 0; i < mp.size(); i++){
            ans *= 2;
            ans %= 1000000007;
        }
        cout << ans << endl;
    }
}
