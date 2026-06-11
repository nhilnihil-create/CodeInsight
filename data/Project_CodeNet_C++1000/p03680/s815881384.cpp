#include <bits/stdc++.h>
using namespace std;
typedef long long ll;



int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    #ifndef ONLINE_JUDGE
        freopen("input.txt","r",stdin);
        freopen("output.txt","w",stdout);
    #endif
    
    int n,i=0,ans=0;
    cin>>n;

    vector<int> a(n);
    vector<bool> v(n,false);

    for(int i=0;i<n;i++){
        cin>>a[i];
    }

    while(true){
        if(v[i]){
            ans=-1;
            break;
        }else if(a[i]==2){
            ans++;
            break;
        }
        v[i]=true;
        i=a[i]-1;
        ans++;
    }
    cout<<ans<<endl;
    
}
