#include <bits/stdc++.h>
using namespace std;

int main(void){
    string O,E;cin>>O>>E;
    string ans;
    for(int i=0;i<O.size()+E.size();i++){
        if(i%2==0){
            ans+=O[i/2];
        }
        else{
            ans+=E[i/2];
        }
    }
    cout<<ans<<endl;
    return 0;
}