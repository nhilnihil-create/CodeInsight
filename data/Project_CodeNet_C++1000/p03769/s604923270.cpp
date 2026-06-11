#include<bits/stdc++.h>
#define mo 1000000007
using namespace std;
long long read(){
    long long xx=0,flagg=1;
    char ch=getchar();
    while((ch<'0'||ch>'9')&&ch!='-')
        ch=getchar();
    if(ch=='-'){
        flagg=-1;
        ch=getchar();
    }
    while(ch>='0'&&ch<='9'){
        xx=xx*10+ch-'0';
        ch=getchar();
    }
    return xx*flagg;
}
void pus(long long xx,long long flagg){
    if(xx<0){
        putchar('-');
        xx=-xx;
    }
    if(xx>=10)
        pus(xx/10,0);
    putchar(xx%10+'0');
    if(flagg==1)
        putchar(' ');
    if(flagg==2)
        putchar('\n');
    return;
}
long long ksm(long long u,long long v){
	long long o=1;
	while(v){
		if(v&1)
			o=o*u%mo;
		u=u*u%mo;
		v>>=1;
	}
	return o;
}
long long n,i,top,zhan[200005],head,tail,dui[200005];
int main(){
    //freopen(".in","r",stdin);
    //freopen(".out","w",stdout);
   	n=read();
   	while(n){
		if(n&1){
			n>>=1;
			top++;
			zhan[top]=2;
		}
		else{
			n--;
			top++;
			zhan[top]=1;
		}	
	}
	head=top+1;tail=top;
	for(i=top;i>=1;i--){
		if(zhan[i]==1){
			head--;
			dui[head]=top-i+1;
		}
		else{
			tail++;
			dui[tail]=top-i+1;
		}
	}
	pus(top<<1,2);
	for(i=head;i<=tail;i++)
		pus(dui[i],1);
	for(i=1;i<=top;i++)
		pus(i,1);
	cout<<endl;
    return 0;
}