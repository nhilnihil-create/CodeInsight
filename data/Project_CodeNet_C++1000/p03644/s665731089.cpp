#include<iostream>
#include<math.h>
#include<string>
#include<vector>
using namespace std;

#define rep(i,n) for(i=0;i<n;i++)
int main(){
    int i;
    int n;
    cin>>n;
    int max=0;
    int ans=0;
    if(n==1){
        cout<<1;
        return 0;
    }
    rep(i,n+1){
        int cnt=0;
        int p=i;
        while(p%2==0 && p!=0){
            cnt++;
            p/=2;
        }
        if(cnt>max){
            max=cnt;
            ans=i;
        }
    }
    cout<<ans;
}
