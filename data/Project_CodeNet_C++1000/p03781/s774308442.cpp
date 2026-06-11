#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int  main(){
    ll x;
    ll i=0;
    cin>>x;
    while(x>0){
        i++;
        x-=i;
    }
    cout<<i<<endl;
return 0;
}
