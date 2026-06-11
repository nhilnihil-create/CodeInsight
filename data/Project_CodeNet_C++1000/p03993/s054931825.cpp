#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
const ll mxn= 2e5+5;
// check for forloop
// intialize variable
// overflow
// go for easy solution
#define mod 1000000007
ll INF = 1000000000000000005LL;
#define endl '\n'
void rishabh(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
}
int main(){
    int n;
    cin>>n;
    int arr[mxn];
    for(int i=1;i<=n;i++){
        cin>>arr[i];
    }
    int ans=0;
    for(int i=0;i<=n;i++){
        if(arr[arr[i]]==i)ans++;
    }
    cout<<ans/2;
}