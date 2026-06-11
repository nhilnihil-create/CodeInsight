#include <bits/stdc++.h>
using namespace std;
 
int main() {
    long long Q,H,S,D,N;
    cin >>Q>>H>>S>>D>>N;
    long long q=Q*8,h=H*4,s=S*2,d=D;
    long long X=min((min(q,h)),min(s,d));
    long long Y=min((min(Q*4,H*2)),S);
    if(N%2==0){
        cout <<N/2*X<<endl;
    }
    else{
        cout <<N/2*X+Y<<endl;
    }
}