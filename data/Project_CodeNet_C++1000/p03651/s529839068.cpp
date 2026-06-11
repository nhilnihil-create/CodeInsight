#include<iostream>
using namespace std;
int gcd(int x,int y){return y?gcd(y,x%y):x;}
int N,K,A,ma,g;
int main(void){
    cin>>N>>K;
    for(int i=0;i<N;i++){cin>>A;ma=max(ma,A);g=(i?gcd(g,A):A);}
    cout<<(K<=ma&&K%g==0?"":"IM")<<"POSSIBLE"<<endl;
    return 0;
}