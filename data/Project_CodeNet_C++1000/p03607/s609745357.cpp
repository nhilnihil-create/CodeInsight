#include <bits/stdc++.h>
using namespace std;

int main() {
    int N;
    cin >> N;
    
    vector<long long> A(N);
    for (int i = 0; i < N; i++){
        cin >> A.at(i);
    }

    sort(A.begin(),A.end());
    int ans=0;
    int cnt=1;
    for (int i = 0; i < N-1; i++){
        if(A[i]==A[i+1]){
            cnt++;
            if(i==N-2){
                ans=ans+cnt%2;
            }
        }
        else{
            ans=ans+cnt%2;
            cnt=1;
            if(i==N-2){
                ans++;
            }
        }
    }

    cout << ans << endl;

}