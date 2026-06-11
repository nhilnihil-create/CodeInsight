#include <bits/stdc++.h>
using namespace std;
#define sci1(a) scanf("%d",&a)
#define sci2(a,b) scanf("%d %d",&a,&b)
#define sci3(a,b,c) scanf("%d %d %d",&a,&b,&c)
#define scs(s) scanf("%s",s)
#ifndef GET_MACRO

#define GET_MACRO(__1,__2,__3,NAME,...) NAME

#endif // GET_MACRO

#define sci(...) GET_MACRO(__VA_ARGS__,sci3,sci2,sci1)(__VA_ARGS__)
#define ll long long
#define pii pair<int,int>
#define mp(a,b) make_pair(a,b)
#define LSB(i) ((i)&(-i))
#define read freopen("input.txt","r",stdin)
#define write freopen("output.txt","w",stdout)
#define infl  0x7ffffffffffffff
#define infi  0x7fffffff
#define fill_(a,b) fill(a.begin(),a.end(),b)
#define pb push_back
#define xx first
#define yy second

int main(){
    ll data[7];
    int i;
    ll ans=0;
    for(i=0;i<7;i++)cin>>data[i];
    ans+=data[1];
    if(data[0]%2){
        ans+=data[0]-1;
        if((data[3]%2||data[4]%2)&&data[3]>0&&data[4]>0){
            ans+=3;
            data[3]--;
            data[4]--;
        }
    }
    else{
        if(data[3]%2&&data[4]%2&&data[0]>0){
            ans+=data[0]-2;
            ans+=3;
            data[3]--;
            data[4]--;
        }
        else{
            ans+=data[0];
        }
    }
    ans+=(data[3]/2)*2;
    ans+=(data[4]/2)*2;
    cout<<ans<<endl;
    return 0;
}
