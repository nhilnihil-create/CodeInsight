#include <bits/stdc++.h>

using namespace std;

int main(){
    long long int N,ans=0;
    bool remain = false;
    cin >> N;
    vector<long long int> A(N);
    for(int i=0;i<N;i++){
        cin >> A[i];
    }

    for(int i=0;i<N;i++){
        if(remain && 0<A[i]){
            ans++;
            A[i]--;
        }
        
        ans += A[i]/2;

        if(A[i]%2==1){
            remain = true;
        }else{
            remain = false;
        }
    }

    cout << ans << endl;
}