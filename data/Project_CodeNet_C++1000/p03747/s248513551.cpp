#include <bits/stdc++.h>
using namespace std;
int main(){
    int N,L,T;
    cin>>N>>L>>T;
    int x[N],w[N];
    for(int i=0;i<N;i++)cin>>x[i]>>w[i];
    int count=0;
    int y[N];
    
    for(int i=0;i<N;i++){
        if(w[i]==1) {
          y[i]=(x[i]+T)%L;
        count+=(x[i]+T)/L;

        }
        else {
            y[i]=(x[i]-T)%L;
            count+=(x[i]-T)/L;
            if(y[i]<0){
                y[i]+=L;
                count--;
            }
            
        }
    }
        sort(y,y+N);
        count=(count%N+N)%N;
        for(int i=count;i<N;i++){
            cout<<y[i]<<endl;
            }
        for(int i=0;i<count;i++){
            cout<<y[i]<<endl;
        }
}