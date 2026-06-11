

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
    ll h,w,n;cin>>h>>w>>n;
    vector<i_i> v;
    for(int i=1;i<=n;i++){
        int x,y;cin>>x>>y;
        for(int i=-2;i<=0;i++){
            for(int j=-2;j<=0;j++){
                if(1<=x+i&&x+i<=h-2&&1<=y+j&&y+j<=w-2){
                    v.push_back(make_pair(x+i,y+j));
                }
            }
        }
    }
    sort(v.begin(),v.end());
    ll ans[10];for(int i=1;i<=9;i++)ans[i]=0;
    for(int i=0;i<v.size();i++){
        int count=1;
        while(i+1<v.size()&&v[i]==v[i+1]){
            count++;
            i++;
        }
        ans[count]++;
    }
    ans[0]=(h-2)*(w-2);
    for(int i=1;i<=9;i++)ans[0]-=ans[i];
    for(int i=0;i<=9;i++)cout<<ans[i]<<endl;
    return 0;
}