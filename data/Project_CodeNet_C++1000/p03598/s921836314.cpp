#include<iostream>
#include<math.h>
#include<string>
using namespace std;

#define rep(i,n) for(i=0;i<n;i++)
int main(){
    int i;
    int sum=0;
    int N,K;
    cin>>N>>K;
    int pos[N];
    rep(i,N){
        cin>>pos[i];
    }
    rep(i,N){
        if(abs(pos[i]-K)<abs(pos[i])){
            sum+=2*abs(pos[i]-K);
        }else{
            sum+=2*abs(pos[i]);
        }
    }
    cout<<sum<<endl;
}
