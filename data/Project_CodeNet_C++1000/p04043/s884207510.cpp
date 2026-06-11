
#include<bits/stdc++.h>
//#include<iostream>
//#include<string>

#define ll          long long
#define uint        unsigned int 
#define ld          long double
#define SAM         ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define FOR(i,a,b)  for(int i=a;i<b;++i)
#define RFOR(i,a,b) for(int i=a;i>b;--i)
#define mod         1000000007
#define mxn         200005
#define pb          push_back
#define pii         pair<int,int>
#define f           first
#define s           second
#define sz(x)       (int)x.size()
#define all(x)      x.begin(),x.end()

using namespace std;

int main()
{
    SAM;
    int arr[11];
    memset(arr,0,sizeof(arr));
    FOR(i,0,3)
    {
        int x;
        cin>>x;
        arr[x]++;
    }
    
    if(arr[5]==2 && arr[7]==1)
        cout<<"YES";
    else
        cout<<"NO";
    
    
    return 0;
}


