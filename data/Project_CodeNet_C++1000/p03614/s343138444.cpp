#include <iostream>
#include <bits/stdc++.h>
using namespace std;
const int MAXN = 5e3+5;
map<int,int> m1;
int sz;
int ans;
int main(){
    int n;
    cin>>n;
    for(int i=1;i<=n;i++){
        int x;
        cin>>x;
        if(x==i){
            sz++;
        }else{
            if(sz){
                
                ans+=((sz/2)+(sz%2));
                sz = 0;
            }
        }
        
    }
    if(sz){
               
                ans+=((sz/2)+(sz%2));
                 sz = 0;
            }
    cout<<ans<<endl;
    
}
