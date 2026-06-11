#include <bits/stdc++.h>
#define fast std::ios_base::sync_with_stdio(false); cin.tie(0);cout.tie(0);
using namespace std;

void solve(){
    fast
    int h,w,n;
    cin>>h>>w;
    cin>>n;
    vector<int>v(n+1);
    for(int i=1;i<=n;i++)
         cin>>v[i];
    //sort(v.begin(),v.end());
    int A[h][w];
    int k=1;
    bool b=true;
    for(int i=0;i<h;i++){
        if(b){
            for(int j=0;j<w;j++){
               A[i][j]=k;
               v[k]--;
               if(v[k]==0)
                   k++;
               
            }
            b=false;
        }
        else{
            for(int j=w-1;j>=0;j--){
                A[i][j]=k;
                v[k]--;
               if(v[k]==0)
                   k++;
            }
            b=true;
        }
        
    }
    
    for(int i=0;i<h;i++){
        for(int j=0;j<w;j++){
            cout<<A[i][j]<<" ";
        }
        cout<<"\n";
    }
}
int main()
{
    solve();
    return 0;
}
