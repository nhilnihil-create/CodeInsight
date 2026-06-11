#include<iostream>
using namespace std;

int main(){
    int K,N;
    while(cin>>K>>N){
        int ans=0;
        for(int a=0;a<=K;a++){
            for(int b=0;b<=K;b++){
                int c=N-a-b;
                if(c<0) break;
                else if(c<=K) ans++;
            }
        }
        cout<<ans<<endl;
    }
    return 0;
}
