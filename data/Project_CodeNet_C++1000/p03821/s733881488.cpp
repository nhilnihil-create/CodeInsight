#include<cstdio>
#include<cmath>
#include<iostream>
#include<algorithm>
#include<queue>
using namespace std;
int main(){
    int N;
    long long int A[100000],B[100000];
    cin>>N;
    for(int i=0;i<N;i++)cin>>A[i]>>B[i];
    long long int ans=0;
    for(int i=N-1;0<=i;i--){
        if((A[i]+ans)%B[i]!=0)ans+=B[i]-((A[i]+ans)%B[i]);
    }
    cout<<ans<<endl;
    return 0;
}
