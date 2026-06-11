#include<bits/stdc++.h>
using namespace std;
int main(){
    int n, k;
    cin >> n >> k;
    vector<int> A(n);
    for(int i = 0; i < n; i++)
        cin >> A[i];
    int ans = 0;
    for(int i = 0; i < n; i++){
        if(A[i] <= (k / 2)){
            int typeA = A[i] * 2;
            ans += typeA;
        }
        else if(A[i] > (k/2)){
            int typeB = (k - A[i]) * 2;
            ans += typeB;
        }
    }
    cout<<ans;
    return 0;    
}