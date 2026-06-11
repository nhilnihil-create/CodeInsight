#include<iostream>

using namespace std;
typedef long long ll;

ll n,a[330][330]={0};
ll res=0;

signed main(){
    cin>>n;
    for(int i=0;i<n;++i){
        for(int j=0;j<n;++j)cin>>a[i][j];
    }

    bool f;
    for(int i=0;i<n-1;++i){
        for(int j=i+1;j<n;++j){
            f=true;
            for(int k=0;k<n;++k){
                if(k!=i&&k!=j){
                    if(a[i][j]>a[i][k]+a[k][j]){
                        cout<<-1<<endl;
                        return 0;
                    }
                    if(a[i][j]==a[i][k]+a[k][j])f=false;
                }
            }
            if(f)res+=a[i][j];
        }
    }

    cout<<res<<endl;

    return 0;
}