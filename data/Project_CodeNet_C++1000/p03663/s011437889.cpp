//Wrong answer on test inf.
#include<bits/stdc++.h>
#define rep(i,x,y) for (int i=(x);i<=(y);i++)
#define ll long long
#define inf 1000000001
#define y1 y1___
using namespace std;
char gc(){
	static char buf[100000],*p1=buf,*p2=buf;
	return p1==p2&&(p2=(p1=buf)+fread(buf,1,100000,stdin),p1==p2)?EOF:*p1++;
}
#define gc getchar
ll read(){
	char ch=gc();ll x=0;int op=1;
	for (;!isdigit(ch);ch=gc()) if (ch=='-') op=-1;
	for (;isdigit(ch);ch=gc()) x=(x<<1)+(x<<3)+ch-'0';
	return x*op;
}
int len,ans;char op[5];
int init(){
    int k=10;
    for(int i=1;i<=9;i++){
        printf("? %lld\n",k);
        fflush(stdout);
        scanf("%s",op);
        if(op[0]=='N') return i;
        k=k*10;
    }
    k=9;
    for(int i=1;i<=9;i++){
        printf("? %lld\n",k);
        fflush(stdout);
        scanf("%s",op);
        if(op[0]=='Y') return i;
        k=k*10+9;
    }
    return 10;
}
int main(){
	len=init();
    if(len==10)
    {
        printf("! %d\n",1000000000);
        return 0;
    }
	for(int i=1;i<len;i++)
    {
        int l=0,r=9,t=0;
        while(l<=r)
        {
            int mid=(l+r)/2;
            printf("? %d\n",ans*10+mid);
            fflush(stdout);
            scanf("%s",op);
            if(op[0]=='Y')
            {
                t=max(t,mid);
                l=mid+1;
            }
            else
                r=mid-1;
        }
        ans=ans*10+t;
    }
	for(int i=(len==1?1:0);i<=9;i++)
    {
        printf("? %lld\n",((ll)ans*10+i)*10);
        fflush(stdout);
        scanf("%s",op);
        if(op[0]=='Y')
        {
            ans=ans*10+i;
            break;
        }
    }
    printf("! %d\n",ans);
	return 0;
}
