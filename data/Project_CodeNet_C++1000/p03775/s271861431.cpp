#include <bits/stdc++.h>
using namespace std;

int main() {
    long long N; cin >> N;
    int A=floor(sqrt(N));
    int ans=to_string(N).size();
    int result;
    for(int i=1; i<A+1; i++){
        if(N%i==0){
            result=to_string(N/i).size();
            ans=min(ans,result);
        }
    }
    cout << ans << endl;
}