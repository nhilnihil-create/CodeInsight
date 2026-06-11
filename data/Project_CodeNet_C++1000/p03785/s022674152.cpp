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
int main(){
    int n,c,k;
    cin>>n>>c>>k;
    int arr[n];
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    sort(arr,arr+n);
    int i=0,j=0,ans=0;
    while(i<n){
        while(arr[i]+k>=arr[j]&&j-i<c)j++;
        ans++,i=j;
    }
    cout<<ans<<endl;
}