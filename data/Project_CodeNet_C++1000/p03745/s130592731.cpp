#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin >> n;
    
    vector<long long> A(n);
    for (int i = 0; i < n; i++){
        cin >> A.at(i);
    }
    
    int mode=0;;
    int ans=0;
    for (int i = 0; i < n-1; i++){
        if(A[i]<A[i+1]){
            if(mode==2){
                ans++;
                mode=0;
            }
            else{
            mode=1;
            }
        }
        if(A[i]>A[i+1]){
            if(mode==1){
                ans++;
                mode=0;
            }
            else{
            mode=2;
            }
        }
    }
    cout << ans+1 << endl;
}