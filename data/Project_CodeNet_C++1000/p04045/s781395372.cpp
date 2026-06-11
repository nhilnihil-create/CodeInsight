#pragma GCC optimize("Ofast")
#pragma GCC target("avx,avx2,fma")
#pragma GCC optimization("unroll-loops")
#include <bits/stdc++.h>

#define fast_in_out     ios_base::sync_with_stdio(false);cin.tie(0);
using namespace std;
int arr[11];
int main()
{
    fast_in_out
    int n,k,x;
    cin>>n>>k;
    for(int i=0;i<k;i++){
        cin>>x;
        arr[x]=1;
    }

    while(1){
        int cur=n;
        bool chosen=true;
        while(cur>0){
            int d=cur%10;
            cur/=10;
            if(arr[d]){
                chosen=false;
                break;
            }
    }
        if(chosen){
            cout<<n<<'\n';
            return 0;
        }
        n++;
    }
    return 0;
}
