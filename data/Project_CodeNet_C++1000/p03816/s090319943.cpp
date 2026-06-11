#include <bits/stdc++.h>

using namespace std;

int main(){
    int N,sum=0,ans=0;
    cin >> N;
    vector<int> A(100001,0);
    for(int i=0;i<N;i++){
        int a;
        cin >> a;
        A[a]++;
    }

    for(int i=0;i<100001;i++){
        if(A[i]!=0){
            ans++;
            if(A[i]!=1){
                sum += (A[i]-1)%2;
            }
        }
    }

    cout << ans-(sum%2) << endl;
}