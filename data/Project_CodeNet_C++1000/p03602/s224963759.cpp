#include <iostream>
using namespace std;
typedef long long ll;
int n;
ll a[300][300],d[300][300],ans=0;

int main(void){
    cin>>n;
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            cin>>a[i][j];
            d[i][j]=a[i][j];
        }
    }
    for(int k=0;k<n;k++){
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                d[i][j]=min(d[i][j], d[i][k]+d[k][j]);
            }
        }
    }

    for(int i=0;i<n;i++){
        for(int j=i+1;j<n;j++){
            bool f=true;
            for(int k=0;k<n;k++){
                if(k!=i&&k!=j){
                    if(d[i][k]+d[k][j]<a[i][j]){
                        cout<<-1<<endl;
                        return 0;
                    }else if(d[i][k]+d[k][j]==a[i][j]){
                        f=false;
                    }
                }
            }
            if(f){
                ans+=a[i][j];
            }
        }
    }
    cout<<ans<<endl;
}
