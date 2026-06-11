#include<bits/stdc++.h>
using namespace std;
const long long int mod=1e9+7;
int n;
char c[2][55];

int main(){
    cin >> n;
    if(n==1){
        cout << 3;
        return 0;
    }
    char c[2][n];
    long long int ans=1;
    for(int i=0;i<2;i++)for(int j=0;j<n;j++)cin >> c[i][j];
    int j=0;
    while(j<n){
        if(j==0){
            if(c[0][0]==c[1][0]){
                ans*=3;
                j++;
            }
            else{
                ans*=6;
                j+=2;
            }
        }
        else{
            if(c[0][j]==c[1][j]){
                if(c[0][j-1]==c[1][j-1]){
                    ans*=2;
                    ans%=mod;
                    j++;
                }
                else j++;
            }
            else{
                if(c[0][j-1]==c[1][j-1]){
                    ans*=2;
                    ans%=mod;
                    j+=2;
                    }
                else{
                    ans*=3;
                    ans%=mod;
                    j+=2;                           
                    }
            }
        }
    }
    cout << ans;
}