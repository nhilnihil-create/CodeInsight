#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int MOD=1e9+7;
const int INF=1e9;

int main(){
    string s;
    cin>>s;
    int ans=0,d=0;
    for(char c:s){
        if(d>0){
            if(c=='g')ans+=1;
            d--;
        }
        else{
            if(c=='p')ans-=1;
            d++;
        }
    }
    cout<<ans<<endl;
}
