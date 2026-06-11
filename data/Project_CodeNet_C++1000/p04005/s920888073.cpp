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
    ll arr[3];
    cin>>arr[0]>>arr[1]>>arr[2];
    sort(arr,arr+3);
    if(arr[2]%2)
    cout<<arr[0]*arr[1];
    else cout<<0;
}