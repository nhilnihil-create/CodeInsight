#include<iostream>
using namespace std;
long long N,A,S,ans;
int main(void){
    cin>>N;
    for(int i=0;i<N;i++){cin>>A;if(A)S+=A;else ans+=S/2LL,S=0LL;}
    cout<<ans+S/2LL<<endl;
    return 0;
}