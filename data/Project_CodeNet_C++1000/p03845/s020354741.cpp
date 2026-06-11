#include<bits/stdc++.h>
using namespace std;

int main(){
        int n,m,total=0;
        cin>>n;
        int t[n];
        for(int i=0;i<n;i++){
                cin>>t[i];
                total+=t[i];
        }
        cin>>m;
        int p[m],x[m];
        for(int i=0;i<m;i++){
                cin>>p[i]>>x[i];
                cout<<total-t[p[i]-1]+x[i]<<endl;
        }

}