#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
const int mxn= 5e5+5;
// check for forloop
// take input
// overflow
// intialize variable
// go for easy solution
#define mod 1000000007
ll INF = 1000000000000000005LL;
#define endl '\n'
void rishabh(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
}
int n,k;
int main(){
    cin>>n>>k;
    int even=0, odd=0; ll ans=0;
    for(int i=0;i<n;i++){
        int x;
        cin>>x;
        if(x%2==0){
            even++;
        }
        else odd++; 
    }
    if(k==0){
        if(odd>2)
        ans=pow(2, odd+even-1);
        if(odd==2){
            ans=pow(2,even+1);
        }
        if(odd<2){
            if(even)
            ans=pow(2,even);
        }
        cout<<ans;
    }
    else {
        if(odd==0)cout<<0;
        else {
            ans=pow(2, odd+even-1);
            cout<<ans;
        }
    }

}

