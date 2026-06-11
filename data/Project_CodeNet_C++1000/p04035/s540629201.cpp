#include <bits/stdc++.h>
#define int long long
#define gcd            __gcd
#define setbits(x)     __builtin_popcountll(x)
#define zrobits(x)     __builtin_ctzll(x)
#define mod            1000000007
#define inf            1e18
#define deci(x,y)      fixed<<setprecision(y)<<x
#define PI             3.141592653589793238
using namespace std;
int power(int n,int p){
    int x = n;
    int ans = 1;
    while(p > 0){
        if(p&1)
            ans= (ans*x)%mod;
        x= (x*x) % mod;
        p = p>>1;
    }
    return ans;
}

int modinv(int a){
    return power(a, mod - 2);
}

int32_t main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n,l,sum=0,index;
    cin>>n>>l;
    int arr[n];
    cin>>arr[0];
    for(int i=1;i<n;i++){
        cin>>arr[i];
        if( sum < (arr[i] + arr[i-1])){
            sum = arr[i] + arr[i-1];
            index = i-1;
        }
    }
    if(sum >= l){
        cout<<"Possible"<<endl;
        for(int i=1;i<=index;i++)
            cout<<i<<endl;
        for(int i=n-1;i> index;i--)
            cout<<i<<endl;
    } else cout<<"Impossible"<<endl;
    return 0;
}