#include<bits/stdc++.h>
using namespace std;

using Lint=long long;

int main()
{
        int N; cin>>N;
        vector<int> a(N);
        for(int i=0;i<N;i++) cin>>a[i];

        Lint ans=a[0]-1;
        int mx=1;
        for(int i=1;i<N;i++){
                if(a[i]%(mx+1)!=0){
                        ans+=a[i]/(mx+1);
                }else if(a[i]==mx+1){
                        mx=mx+1;
                }else{
                        ans+=1+(a[i]-(mx+2))/(mx+1);
                }
        }
        cout<<ans<<endl;
        return 0;
}
