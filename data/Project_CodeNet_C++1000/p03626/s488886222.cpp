#include <bits/stdc++.h>
#include <stdlib.h>
using namespace std;
typedef long long ll;
const ll mod=1000000007;

ll ans=1;

int main(){
    int N;
    cin>>N;
    string S,t;
    cin>>S>>t;
    vector<int> d;
    char memory;
    int i=0;
    if(N==1) d.push_back(1);
    if(N>1){
    while(i<N-1){
        if(S.at(i)==S.at(i+1)){
            d.push_back(2);
            i+=2;
        }
        else{
            d.push_back(1);
            if(i==N-2) d.push_back(1);
            i++;
            
        }
    }
    }
    //for(int i=0;i<d.size();i++) cout<<d.at(i);
    //cout<<endl;

    if(d.at(0)==1) ans=3;
    else ans=6;
    if(d.size()>1){
    for(int i=1;i<d.size();i++){
        if(d.at(i)==1 && d.at(i-1)==1) ans*=2;
        if(d.at(i)==2 && d.at(i-1)==1) ans*=2;
        if(d.at(i)==2 && d.at(i-1)==2) ans*=3;
        ans=ans%mod;
    }
    }
    cout<<ans<<endl;
    
}