#include <bits/stdc++.h>
#define pi 3.14159
using namespace std;
typedef long long LL;
const LL MOD = 1e9 + 7;
const int N = 1e5 + 7, M = 1e7, OO = 0x3f3f3f3f;
#define AC ios::sync_with_stdio(0);cin.tie(0);cout.tie(0); cin.sync_with_stdio(0);
int main()
{
int n,array1[N],i,sum=1,flag=1;
scanf("%d",&n);
set<int>s;
map<int,int>mp;
for(i=0;i<n;++i){
    scanf("%d",&array1[i]);
    int x,y;
    x=((n-1)+array1[i])/2;
    y=(n-1)-x;
    if(x+y==n-1){
        s.insert(array1[i]);
        mp[array1[i]]++;
        if(mp[array1[i]]>2){
            flag=0;
            break;
        }
        if(array1[i]==0&&mp[array1[i]]>1){
            flag=0;
            break;
        }
    }
    else{
        flag=0;
        break;
    }
}
if(flag){
    if(s.find(0)!=s.end()){
        s.erase(0);
    }
    for(i=0;i<s.size();++i){
        sum=(1ll*sum*2)%MOD;
    }
    printf("%d",sum);
}
else{
    printf("0");
}



    return 0;
}
