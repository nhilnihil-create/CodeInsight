#include<iostream>
using namespace std;

int main() {
    long N;
    cin>>N;
    long ans;
    long sum;
    for(long i=1;i<=N;++i){
        if(2*N<=i*(i+1)){
            ans = i;
            sum = i*(i+1)/2;
            break;
        }
    }
    long hiku = sum - N;
    for(int i=1;i<=ans;++i){
        if(i==hiku)continue;
        cout<<i<<endl;
    }
}
