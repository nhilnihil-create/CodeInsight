

#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<math.h>
#include<stack>
#include<queue>
#include<vector>
#include<algorithm>
#include<string>
#include<iostream>
#include<set>
#include<map>
#include<bitset>

using namespace std;
typedef long long ll;
#define i_7 1000000007
#define i_5 1000000005

ll mod(ll a){
    ll c=a%i_7;
    if(c>=0)return c;
    else return c+i_7;
}
typedef pair<int,int> i_i;
typedef pair<ll,ll> l_l;
#define inf 100000000/*10^8*/



////////////////////////////////////////


int main(){
    int n,gomi;cin>>n>>gomi;
    int a[n];for(int i=0;i<=n-1;i++)cin>>a[i];
    int min=a[0],maxd=0;int count=0;int maxcount=0;
    for(int i=1;i<=n-1;i++){
        if(a[i]-min>maxd){
            maxd=a[i]-min;
            if(count>maxcount)maxcount=count;
            count=1;
        }else if(a[i]-min==maxd)count++;
        
        if(a[i]<min)min=a[i];
    }
    maxcount=max(maxcount,count);
    cout<<maxcount<<endl;
    
    
    return 0;
}
