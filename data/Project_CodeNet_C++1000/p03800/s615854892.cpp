#include <bits/stdc++.h>

using namespace std;
#define int long long

const int INF = 200000000007;


  
signed main(){
    int n;
    string s;
    cin>>n>>s;
    bool a[n];
    for(int i=0;i<n;i++){
        if(s[i]=='o')a[i]=false;
        else a[i]=true;
    }
    bool ans[n];
    if(n%3==0){
        ans[0]=0;ans[1]=0;ans[2]=0;
        for(int i=0;i<n/3;i++){
            ans[(3*i+3)%n]=ans[3*i]^a[3*i+1]^a[3*i+2];
            ans[(3*i+4)%n]=ans[3*i+1]^a[3*i+2]^a[3*i+3];
            ans[(3*i+5)%n]=ans[3*i+2]^a[3*i+3]^a[3*i+4];
        }
        if(ans[0]==0&&ans[1]==0&&ans[2]==0){
            for(int i=0;i<n;i++){
                if(ans[i]^a[1])cout<<'W';
                else cout<<'S';
            }
        }else cout<<-1;
    }else{
        ans[0]=0;
        for(int i=0;i<n;i++){
            ans[(3*i+3)%n]=ans[(3*i)%n]^a[(3*i+1)%n]^a[(3*i+2)%n];
        }
        if(ans[0]==0){
            bool k=ans[0]^ans[1]^ans[2]^a[1];
            for(int i=0;i<n;i++){
                if(ans[i]^k)cout<<'W';
                else cout<<'S';
            }
        }else cout<<-1;
    }
   
    

    
    return 0;
}