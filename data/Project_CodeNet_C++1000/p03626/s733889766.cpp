#include <bits/stdc++.h>
#define rep(i,N) for(int i=0;i<N;i++)
using namespace std;
long long  INF=1000000000000000000;
long long mod=1000000007;
using namespace std;


int main(){

int N;
cin>>N;
string s1;
string s2;
cin>>s1;
cin>>s2;
long long ans=3;



bool straight=false;

int p=1;
    if(s1[0]==s2[0]){
        if(straight){
            ans=3;
        }
        straight=true;
    }
    else{
        straight=false;
        ans=6;
        p++;
    }

for(int i=p;i<N;i++){
    if(s1[i]==s2[i]){
        if(straight){
            ans*=2;
        }
        straight=true;
    }
    else{
        if(straight){
            ans*=2;
        }
        else{
        ans*=3;
        }
        straight=false;
        i++;
    }
    if(ans>mod){
        ans%=mod;
    }
}

cout<<ans<<endl;
 return 0;
}
/*

3
aab
ccb

6


1
Z
Z

3

52
RvvttdWIyyPPQFFZZssffEEkkaSSDKqcibbeYrhAljCCGGJppHHn
RLLwwdWIxxNNQUUXXVVMMooBBaggDKqcimmeYrhAljOOTTJuuzzn

958681902
*/