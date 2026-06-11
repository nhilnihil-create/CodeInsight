#include <bits/stdc++.h>
using namespace std;

int N,C,K;

int main(){
    cin>>N>>C>>K;
    int T[N];
    for(int i=0;i<N;i++){
        cin>>T[i];
    }
    sort(T,T+N);
    int r=1,bus=0,time=T[0];
    for(int i=1;i<N;i++){
        if(r<C){
            if(T[i]<=time+K){
                r++;
            }else{
                bus++;
                r=1;
                time=T[i];
            }
        }else if(r==C){
            bus++;
            r=1;
            time=T[i];
        }
    }
    bus++;
    cout<<bus<<endl;
    return 0;
}