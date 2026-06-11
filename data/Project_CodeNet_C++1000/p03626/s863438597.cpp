#include <iostream>
using namespace std;
int n;
char c[2][60];
int main(){
    cin>>n;
    for(int i=0;i<2;i++)for(int j=0;j<n;j++)cin>>c[i][j];
    long long ans=1LL;
    int i=0;
    while(i<n){
        if(c[0][i]==c[1][i]){
            if(i==0) ans*=3;
            else if(c[0][i-1]==c[1][i-1])ans*=2;
            i++;
        }else{
            if(i==0) ans*=6;
            else if(c[0][i-1]==c[1][i-1])ans*=2;
            else ans*=3;
            i+=2;
        }
        ans%=1000000007;
    }
    cout<<ans<<endl;
}