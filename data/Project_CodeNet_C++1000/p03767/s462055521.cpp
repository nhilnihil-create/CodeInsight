#include<bits/stdc++.h>
using namespace std;
#define endl "\n"
#define ll long long
#define MOD 1000000007
#define FAST ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);

bool cmp(int a,int b){
    return a>b;
}

int main(){
    FAST;
    ll n,i,sum=0;
    cin>>n;
    ll ar[3*n];
    for( i=0;i<3*n;i++){
        cin>>ar[i];
    }
    sort(ar,ar+(3*n),cmp);
    for(i=1;n;i+=2,n--){
        sum+=ar[i];
    }
    cout<<sum;
}