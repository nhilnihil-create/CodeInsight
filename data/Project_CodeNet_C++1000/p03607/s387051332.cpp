#include <bits/stdc++.h>
using namespace std;
 
int main(void){
    long long N;cin>>N;
    std::vector<long long>A(N+1); // AのサイズをN+1にする
    for(long long i=0;i<N;i++){
        cin>>A[i];
    }
	A[N]=1000000007; // Aの最後に他の要素と一致しない要素(番兵)を入れる
    sort(A.begin(),A.end());
    long long ans=0;
    long long tmp=0;
    for(long long i=1;i<N+1;i++){ // 回す回数を1回増やす
        if(A[i]==A[i-1]){
            tmp++;
        }
        else{
            if(tmp%2==0){
                ans++;
            }
            tmp=0;
        }
    }
    cout<<ans<<endl;
}
