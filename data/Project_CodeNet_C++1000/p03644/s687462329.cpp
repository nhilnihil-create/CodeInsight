#include<bits/stdc++.h>
#define rep(i,n) for(int i=0;i<(n);i++)

using ll=long long;
using namespace std;

int main(){
    int n;
    cin>>n;
    
    bool flag=true;
    int i=1;
    while(flag){
        if(pow(2,i)>n){
            i--;
            flag=false;
            continue;
        }
        i++;
    }
    
    cout<<pow(2,i)<<endl;
    return 0;
}
