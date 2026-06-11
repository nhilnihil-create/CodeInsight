#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
typedef double dd;
#define all(v) v.begin(),v.end()
#define endl "\n"
#define clr(n, r) memset(n,r,sizeof(n));

void fast() {

    cin.tie(0);
    cin.sync_with_stdio(0);
}
long long binpow(long long a, long long b, long long m) {
    a %= m;
    long long res = 1;
    while (b > 0) {
        if (b & 1)
            res = res * a % m;
        a = a * a % m;
        b >>= 1;
    }
    return res;
}
int freq[26];

int main() {
    fast();
    ll n;cin>>n;
    int arr[n];
    int freq[n]={0};
    for (int i = 0; i <n ; ++i) {
        cin>>arr[i];
        if(((n%2==0)&&(arr[i]%2==0))||((n%2!=0)&&(arr[i]%2!=0)))return cout<<0,0;
        freq[arr[i]]++;
    }
    for (int j = n-1; j >=0 ; j-=2) {
        if(j>=1&&freq[j]!=2)return cout<<0,0;;
        if(j==0&&freq[j]!=1)return cout<<0,0;
    }
    ll mod=1e9+7;
    cout<<binpow(2,n/2,mod);
}