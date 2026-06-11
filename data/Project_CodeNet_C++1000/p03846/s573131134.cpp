#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#define int long long
using namespace std;
const int X=1000000007;
signed main(){
    int n;
    cin>>n;
    vector<int> a(n);
    
    for(int i=0;i<n;i++){
        cin>>a[i];
    }
    
    int init;
    if(0==n%2){
        init =1;
    }else{
        init=0;
    }
    bool flag=true;
    vector<int> memo(n,0);
    for(int i=0;i<n;i++) memo[a[i]]++;
    for(int i=0;i<n;i++){
        if(0==n%2){
            if((1==i%2&2!=memo[i])||(0==i%2&0!=memo[i])){
                flag=false;
                break;
            }
        }else{
            if(0==i){
                if(1==memo[i]) continue;
                else{
                    flag=false;
                    break; 
                }
            }else{
                if((1==i%2&0!=memo[i])||(0==i%2&2!=memo[i])){
                    flag=false;
                    break;
                }
            }
        }
    }
    if(flag){
        int ret=1;
        for(int i=0;i<n/2;i++){
            ret*=2;
            ret%=X;
        }
        cout<<ret<<endl;
    }else{
        cout<<0<<endl;
    }
    return 0;
}