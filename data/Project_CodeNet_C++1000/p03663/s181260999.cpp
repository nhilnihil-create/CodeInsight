#include <iostream>
#include <bits/stdc++.h>
using namespace std;
bool query(long long x){
    cout<<"? "<<x<<endl;
    string y;
    cin>>y;
    cout.flush();
    if(y=="Y"){
        return true;
    }
    return false;
}
int main(){
    long long dig = 1e9;
    if(!query(dig)){
        while(!query(dig)){
            dig/=(long long)10;
        }
        long long l = dig;
        long long r = ((long long)10*dig)-1;
        long long ans = 0;
        while(l<=r){
            long long mid = (l+r)/2;
            if(query((long long)10*mid)){
                r= mid-1;
                ans =mid;
            }else{
                l=mid+1;
            }
        }
        cout<<"! "<<ans<<endl;
    }else{
        long long ans = 10;
        while(!query(ans-1)){
            ans*=(long long)10;
        }
        ans/=(long long)10;
        cout<<"! "<<ans<<endl;
    }
}
