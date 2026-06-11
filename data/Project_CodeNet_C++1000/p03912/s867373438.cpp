#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define all(x) (x).begin(),(x).end()
const int mod=998244353,MAX=1<<18,INF=1<<30;

int main(){
    
    int N,M;cin>>N>>M;
    vector<int> X(N),cnt(M);
    map<int,int> MA;
    for(int i=0;i<N;i++){
        cin>>X[i];
        cnt[X[i]%M]++;
        MA[X[i]]++;
    }
    int ans=0;
    for(int i=0;i<M;i++){
        if(i==0){
            ans+=cnt[i]/2;
            cnt[i]%=2;
        }else if(i+i==M){
            ans+=cnt[i]/2;
            cnt[i]%=2;
        }else{
            int a=min(cnt[i],cnt[M-i]);
            ans+=a;
            cnt[i]-=a;cnt[M-i]-=a;
            
            for(int j=i;j<=100000;j+=M){
                if(MA[j]>=2){
                    ans+=min(cnt[i],MA[j])/2;
                    cnt[i]-=min(cnt[i],MA[j])/2*2;
                }
            }
            
        }
    }
    
    cout<<ans<<endl;
}
