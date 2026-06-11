#include<iostream>

using namespace std;

int main(){
    int K,S,z,count=0;
    cin>>K>>S;
        for(int i=0;i<=K;++i){
            for(int j=0;j<=K;++j){
                z=S-i-j;
                if(z>=0&&z<=K)count++;
            }
        }
    cout<<count;
}
