#include <bits/stdc++.h>
 
using namespace std;
#define int long long
const int MAX = 2001;
const int MOD = 1000000007;
 
 



 
signed main(){
    int n;
    cin>>n;
    int x1,p[n-1];
    cin>>x1;
    int s,t;
    s=x1;
    for(int i=0;i<n-1;i++){
        cin>>t;
        p[i]=t-s;
        swap(t,s);
    }
    int m,k,a,q[n-1];
    cin>>m>>k;
    for(int i=0;i<n-1;i++)q[i]=i;
    for(int i=0;i<m;i++){
        cin>>a;
        swap(q[a-2],q[a-1]);
    }
    int st=0,s0,s1,count;
    int ban[n-1];
    fill(ban,ban+n-1,-1);
    while(true){
        count=1;
        while(st<n-1&&ban[st]!=-1)st++;
        if(st==n-1)break;
        s0=st;
        while(q[s0]!=st){
            s0=q[s0];
            count++;
        }
        s0=st;
        s1=st;
        count=k%count;
        while(count!=0){
            s1=q[s1];
            count--;
        }
        while(ban[s0]==-1){
            ban[s0]=s1;
            s0=q[s0];
            s1=q[s1];
        }

    }
    cout<<x1<<endl;
    for(int i=0;i<n-1;i++){
        x1+=p[ban[i]];
        cout<<x1<<endl;
    }


    return 0;
}