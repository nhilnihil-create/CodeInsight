#include<iostream>
#include<algorithm>
#include<vector>
#include<map>
#include<string>
#define rep(i,N) for(int i=0;i<N;i++)

long long  INF=1000000000000000000;
long long mod=1000000007;
using namespace std;

void sayNo(){
    cout<<"0"<<endl;
    return;
}
int main(){

long long  N;
cin>>N;
long long T[N+1],A[N+1];

for(int i=1;i<=N;i++){
    cin>>T[i];
}

for(int i=1;i<=N;i++){
    cin>>A[i];
}
long long vt[N+1]={};
long long va[N+1]={};
vt[1]=T[1];
va[N]=A[N];
long long ans=1;
if(T[N]!=A[1]){
    cout<<"0"<<endl;
    return 0;
}

for(int i=1;i<N;i++){
    if(T[i]<T[i+1]){
        if(T[i+1]>A[i+1]){
            sayNo();
            return 0;
        }
        vt[i+1]=T[i+1];
    }
}
for(int i=N;i>1;i--){
    if(A[i]<A[i-1]){
        if(A[i-1]>T[i-1]){
            sayNo();
            return 0;
        }
        va[i-1]=A[i-1];
    }
}
for(int i=1;i<=N;i++){
    if(va[i]==0 && vt[i]==0){
        long long t=min(T[i],A[i]);
        if(t>mod){
            t%=mod;
        }
        ans*=t;
        if(ans>mod){
            ans%=mod;
        }
    }
}
/*
for(int i=1;i<=N;i++){
    cout<<v[i]<<" ";
}
cout<<endl;
*/
cout<<ans<<endl;
 return 0;
}
/*
5
1 3 3 3 3
3 3 2 2 2

4


5
1 1 1 2 2
3 2 1 1 1

0


10
1 3776 3776 8848 8848 8848 8848 8848 8848 8848
8848 8848 8848 8848 8848 8848 8848 8848 3776 5

884111967


1
17
17

1

*/