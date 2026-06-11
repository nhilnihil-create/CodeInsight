#include<bits/stdc++.h>
using namespace std;

int main(){
    int n;
    cin>>n;
    vector<int> a(2*n-1);
    for(int i=0;i<2*n-1;i++)  cin>>a[i];

    int lb=1,ub=2*n;
    while(ub-lb>1){
        int mid=(lb+ub)/2;
        vector<int> flag(2*n-1);
        for(int i=0;i<2*n-1;i++){
            flag[i]=(mid<=a[i]);
        }
        int l=0;
        bool bl=flag[0];
        for(int i=1;i<=n-1;i++){
            if(flag[i]==flag[i-1]) l=i,bl=flag[i];
        }
        int r=2*n-2;
        bool br=flag[2*n-2];
        for(int i=2*n-3;i>=n-1;i--){
            if(flag[i]==flag[i+1]) r=i,br=flag[i];
        }
        bool f=(n-1-l<=r-n+1 ? bl : br);
        
        if(l==0 && r==2*n-2){
            f=((n-1)%2)^flag[n-1];
        }
        if(f) lb=mid;
        else ub=mid;
    }
    cout<<lb<<endl;

    return 0;
}