#include <iostream>
using namespace std;
typedef long long ll;
ll n,s[300][300],ans,d[300][300];
int main(void){
    cin>>n;
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            cin>>s[i][j];
            ans+=s[i][j];
        }
    }
    for(int k=0;k<n;k++){
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                if(i==j)continue;
                if(s[i][j]>s[i][k]+s[k][j]){
                    cout<<-1<<endl;
                    return 0;
                }
                if(s[i][j]==s[i][k]+s[k][j]&&s[i][k]>0&&s[k][j]>0){
                    //cout<<s[i][j]<<" "<<s[i][k]<<" "<<s[k][j]<<endl;
                    if(d[i][j]==0)ans-=s[i][j];
                    d[i][j]=1;
                }
            }
        }
    }
    cout<<ans/2<<endl;
}
