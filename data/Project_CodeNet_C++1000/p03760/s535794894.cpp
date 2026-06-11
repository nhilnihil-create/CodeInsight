#include <bits/stdc++.h>
#define f(i,j,k) for(int i=j;i<k;i++)
using namespace std;
int main(){
    string o,e;
    cin>>o;
    cin>>e;
    string ans;
    f(i,0,o.size()+e.size()){
        if(i%2==0){
            ans=ans+o[i/2];
        }
        else{
            ans=ans+e[i/2];
        }
    }
    cout<<ans<<endl;
    return 0;
}
