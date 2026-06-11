#include<bits/stdc++.h>
using namespace std;
typedef long long ll;



signed main(){
    ios::sync_with_stdio(false);
	cin.tie(0);

    int n,m;
    cin>>n>>m;
    int a[n][m];
    for(int i=0;i<n;i++)for(int j=0;j<m;j++){
        cin>>a[i][j];
        a[i][j]--;
    }

    int low=-1,up=301,mid;
    while(up-low>1){
        mid = (low+up)/2;
        int p[n]={};
        bool pos = true;
        int use=0;
        bool ng[m]={};

        while(use<m){
            pos = true;
            int cnt[m]={};
            for(int i=0;i<n;i++){
                while(p[i]<m && ng[a[i][p[i]]]){
                    p[i]++;
                }
                cnt[a[i][p[i]]]++;
            }
            for(int i=0;i<m;i++){
                if(cnt[i] > mid){
                    if(!ng[i]) use++;
                    ng[i] = true;
                    pos = false;
                }
            }
            
            
            if(pos) break;
        }
        if(pos){
            up = mid;
        }
        else low = mid;
    }
    cout<<up<<endl;
    
}