/*
 1,2,1,0,2
     2+1
       3
*/
#include<bits/stdc++.h>
using namespace std;
using ll=long long int;
int main (){
    int n;cin>>n;
    vector<ll>A(n);
    for(int i=0;i<n;i++)cin>>A[i];
    ll ret=0,sum=0;
    for(int i=0;i<n;i++){
            sum+=A[i];
            if(!A[i]){
                ret+=sum/2;
                sum=0;
            }
    }
    ret+=sum/2;
    cout<<ret<<endl;
    return 0;
}


