#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
const int mxn= 1e5+5;
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
    int arr[n];
    ll sum=0;
    for(int i=0;i<n;i++){
        cin>>arr[i];
        sum=sum+arr[i];
    }
    int q;
    cin>>q;
    while(q--){
        int pos, val;
        cin>>pos>>val;
        cout<<sum-arr[pos-1]+val<<endl;
    }
}