#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

#define  optimize   ios::sync_with_stdio(0); cin.tie(0);
#define PI  acos(-1.0)
#define RESET(a, b) memset(a, b, sizeof(a))
#define pb push_back

int main()
{
     optimize
     int n,k;
     cin>>n>>k;
     int a[n+2];
     ll sum=0;
     vector<int>v;
     for(int i=1;i<=n;i++){
        cin>>a[i];
        sum+=a[i];
     }
     if(sum<k) cout<<"Impossible\n";
     else{
        for(int i=1;i<n;i++){
            if(a[i]+a[i+1]>=k){
                if(i>1){
                    for(int j=1;j<i;j++) v.pb(j);
                }
                if(i+1 <n){
                    for(int j=n-1;j>i;j--) v.pb(j);
                }
            v.pb(i);
            cout<<"Possible\n";
            for(int i=0;i<v.size();i++) cout<<v[i]<<"\n";
            return 0;
            }
        }
        cout<<"Impossible\n";
        return 0;
     }

}
