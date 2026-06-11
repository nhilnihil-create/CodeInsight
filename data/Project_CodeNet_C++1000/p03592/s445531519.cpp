#include <iostream>
#include <string>
#include <vector>
#include <cmath>
#include <algorithm>
#include <iomanip>
using namespace std;
 
int main(){
    int N,M,K; cin>>N>>M>>K;
     if(K%N==0){
            cout<<"Yes"<<endl;
            return 0;
        }
    if(K%M==0){
            cout<<"Yes"<<endl;
            return 0;
        }
    for(int i=0;i<=M;i++){
        for(int j=0;j<=N;j++){
            if(N*i-2*(i*j)+M*j==K){
              //cout<<i<<endl<<j<<endl;
                 cout<<"Yes"<<endl;
                 return 0;
        }
        }
    }
    cout<<"No"<<endl;
}