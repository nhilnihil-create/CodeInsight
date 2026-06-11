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
    int arr[mxn]={};
    for(int i=0;i<n;i++){
        int x;
        cin>>x;
        arr[x]++;
    }
    int ans=arr[0]+arr[1];
    for(int i=1;i<=(int)1e5;i++){       
        ans=max(arr[i]+arr[i-1]+arr[i+1],ans);
    }
    cout<<ans;
}