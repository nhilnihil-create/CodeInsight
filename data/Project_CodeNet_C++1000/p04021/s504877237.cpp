#include<cstdio>
#include<iostream>
#include<algorithm>
#include<cstring>
using namespace std;
#define LL long long
#define mod 1000000007
#define G() Cr=getchar()
int Xr;char Cr;
inline int rd(){   //ｶﾁﾈ・ﾅｻｯ
    Xr=0,G();
    while(Cr<'0'||Cr>'9')G();
    while(Cr>='0'&&Cr<='9')Xr=(Xr<<3)+(Xr<<1)+Cr-'0',G();
    return Xr;
}
int n,ans;
struct node{
	int va,pos;
}e[100005];
bool comp(node x,node y){
	return x.va<y.va;
}
int main(){
    n=rd();
    for(int i=1;i<=n;i++)e[i].va=rd(),e[i].pos=i;
    sort(e+1,e+1+n,comp);
    for(int i=1;i<=n;i++)ans+= (e[i].pos&1)^(i&1);
    cout<<ans/2<<endl;
}