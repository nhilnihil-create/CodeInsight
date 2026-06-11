#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define mod 1000000007

int main(){
    int n,m;cin>>n>>m;
    vector<string> a(n),b(m);
    for(int i=0;i<n;i++){cin>>a[i];}
    for(int i=0;i<m;i++){cin>>b[i];}

    string s="n";
    for(int i=0;i<=n-m;i++){
        for(int j=0;j<=n-m;j++){
            bool ok=true;
            for(int k=0;k<m;k++){
                for(int l=0;l<m;l++){
                    if(a[i+k][j+l]!=b[k][l]){
                        ok=false;
                    }
                }
            }
            if(ok){s="y";break;}
        }
    }

    if(s=="y"){cout<<"Yes"<<endl;}
    else{cout<<"No"<<endl;}

    return 0;
}