#include <bits/stdc++.h>
using namespace std;

const int N=2e5+100;
const int mod=1e9+7;
typedef long long ll;

int n,m;

int f[N],d[N];


int main()
{
    ios::sync_with_stdio(0);cin.tie(0);
    int n;cin>>n;
    string s;
    cin>>s;
    int kl=0,r=0;
    for(int i=0;i<n;i++){
        if(s[i]==')'){
            if(r==0) kl++;
            else r--;
        }
        else r++;
    }

    while(kl--){
        cout<<'(';
    }
    cout<<s;
    while(r--) {
        cout<<')';
    }
    return 0;
}
