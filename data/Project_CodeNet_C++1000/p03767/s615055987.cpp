#include<bits/stdc++.h>
using namespace std;
using ll=long long int;
int main (){
    int n;cin>>n;
    vector<ll>V(3*n);
    for(int i=0;i<3*n;i++)cin>>V[i];
    sort(V.begin(),V.end());
    ll ret=0;
    for(int i=n;i<3*n;i+=2)ret+=V[i];
    cout<<ret<<endl;
    return 0;
}

