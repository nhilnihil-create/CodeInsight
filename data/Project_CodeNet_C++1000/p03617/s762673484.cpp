#include <bits/stdc++.h>
using namespace std;
int main(void){
    // Your code here!
    long long Q,H,S,D,N,n;cin>>Q>>H>>S>>D>>n;
    N=n*100;
    if((Q*8<=H*4)&&(Q*8<=S*2)&&(Q*8<=D)){
        cout<<Q*(N/25)<<endl;
        return 0;
    }
    else if((H*4<=Q*8)&&(H*4<=S*2)&&(H*4<=D)){
        cout<<H*(N/50)<<endl;
        return 0;
    }
    else if((S*2<=Q*8)&&(S*2<=H*4)&&(S*2<=D)){
        cout<<S*n<<endl;
        return 0;
    }
    else if((D<=Q*8)&&(D<=H*4)&&(D<=S*2)){
        if(n%2==0){
            cout<<D*(N/200)<<endl;
            return 0;
        }
        else{
            long long ans=0;
            ans+=D*(N/200);
            long long rest=N%200;
            if((Q*8<=H*4)&&(Q*8<=S*2)){
                ans+=(rest/25)*Q;
                cout<<ans<<endl;
                return 0;
            }
            if((H*4<=Q*8)&&(H*4<=S*2)){
                ans+=(rest/50)*H;
                cout<<ans<<endl;
                return  0;
            }
            if((S*2<=Q*8)&&(S*2<=H*4)){
                ans+=(rest/100)*S;
                cout<<ans<<endl;
                return 0;
            }
        }
    }
    return 0;
}
