#include <bits/stdc++.h>
using namespace std;
#define int long long
signed main(){
    int n,m;
    cin >> n >> m;
    int a[n];
    vector<pair<int,int>> b(n);
    cin >> a[0];
    b[0]=make_pair(a[0],0);
    int k=0;
    int w=0;
    int ans=0;
    for(int i=1;i<n;i++){
        cin >>a[i];
        
        b[i]=make_pair(a[i],i);
        
        if(a[i-1]>a[i]){
            w++;
            k+= m-a[i-1]-1;
            ans+=m+a[i]-a[i-1];

        }else{
            ans+=a[i]-a[i-1];
        }

    }
    sort(b.begin(),b.end());
    int t;
    int gmax =0;
    int g=0;
    for(int i=0;i<n;i++){
        g=k+w*b[i].first;
        if(i==0||((b[i-1].first!=b[i].first)&&(gmax<g)))gmax=g;
        switch(b[i].second){
            case 0:
                k+=-a[0]-1;
                w++;
                break;
           
            default:
                if(b[i].second==n-1){
                    t=a[n-2]-a[n-1];
                    if(t>0)t-=m;
                    k+=t+a[n-1]+1;
                    w--;
                }else{
                    t=a[b[i].second -1]-b[i].first;
                    if(t>0)t-=m;
                    k+=t;
                }
                
                break;
        }
    }
    cout <<ans-gmax;
    return 0;
}