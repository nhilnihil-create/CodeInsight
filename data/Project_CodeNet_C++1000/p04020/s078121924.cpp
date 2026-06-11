#include <bits/stdc++.h>
using namespace std;

int main(){
    int N;
    cin>>N;
    vector<int> A(N);
    long long ans = 0;

    for(int i=0; i<N; i++) cin>>A[i];

    for(int left = 0; left < N; ){
        int right = left;
        long long sum = 0;

        while(A[right] != 0 && right < N){
            sum += A[right];
            right++;
        }

        ans += sum /= 2;
        left = right+1;
    }

    cout<<ans<<endl;

    return 0;
}