#include <bits/stdc++.h>
using namespace std;
const int N=1e5+3;
int arr[N];
int main(){
std::ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    long test;
    test=1;
    // cin>>test;
    while(test--)
    {
        long long i,j,n,q,e=0,t,o=0,c=0,temp,k,maxpeak=0,peak,d;
        string s;
        cin>>n;
        for(i=0;i<n;i++)
        {
            cin>>d;
            arr[d]++;
        }
        for(i=0;i<N;i++)
        {
            if(arr[i]>0)
            {
                if(arr[i]%2==1)
                {
                    o++;
                }
                else e++;
            }
        }
        if(e%2==0)cout<<o+e;
        else cout<<o+e-1;
        
    }
}