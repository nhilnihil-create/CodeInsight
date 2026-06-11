#include <iostream>
#include <bits/stdc++.h>
#include <iomanip>
typedef long long int lli;
#define FAST ios_base::sync_with_stdio(false); cin.tie(NULL);
#define JUGAD freopen("input.txt", "r", stdin); freopen("output.txt", "w", stdout);
#define pb push_back
#define pf push_front
#define mp make_pair
#define ff first
#define ss second
using namespace std;

int main(){
    FAST;
    int n,k;
    cin>>n>>k;
    int ar[10]={0};
    for(int i=0;i<k;i++){
        int c;cin>>c;
        ar[c]=1;
    }
    while(true){
        bool flag=1;
        int x=n;
        while(x){
            int r=x%10;
            if(ar[r]==1){flag=0;break;}
            x/=10;
        }
        if(flag){cout<<n<<endl;return 0;}
        else{n++;}
    }
}


