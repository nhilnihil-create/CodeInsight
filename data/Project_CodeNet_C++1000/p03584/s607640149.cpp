#include <bits/stdc++.h>
using namespace std;
const int MOD =(int)(1e9)+7;
int main()
{
    int N,K;
    cin >> N >> K;
    long long ans=0;
    int a[N];
    vector<long long>B(N);
    for(int i=0;i<N;i++){
        cin >> a[i] >> B[i];
    }

    for(int i=0;i<N;i++){
        bool ok=true;
        for(int j=33;j>=0;j--){
            ok&=((K&(1L<<j))!=0)||((a[i]&(1L<<j))==0);
        }
        if(ok)ans+=B[i];
    }

    for(int b=33;b>=0;b--){
        if((K&(1L<<b))==0)continue;
        long long sum=0;
        for(int i=0;i<N;i++){
            bool ok=true;
            for(int j=33;j>=0;j--){
                if(j>b){
                    ok&=((K&(1L<<j))!=0)||((a[i]&(1L<<j))==0);
                }
                else if(j==b){
                    ok&=((a[i]&(1L<<j))==0);
                }
            }
            if(ok)sum+=B[i];
        }
        ans=max(ans,sum);
    }
    cout << ans << endl;

    return 0;
}