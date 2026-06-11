#include <bits/stdc++.h>

using namespace std;

int main(){
    long long int N,A,B,now=0,ans=0;
    cin >> N >> A >> B;
    vector<long long int> X(N);
    for(int i=0;i<N;i++){
        cin >> X[i];
    }

    now = X[0];

    for(int i=1;i<N;i++){
        if(B<A*(X[i]-now)){
            ans += B;
        }else{
            ans += A*(X[i]-now);
        }
        now = X[i];
    }

    cout << ans << endl;
}