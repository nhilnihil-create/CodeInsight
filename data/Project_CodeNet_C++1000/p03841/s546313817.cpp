#include<bits/stdc++.h>
#define mo 924844033
#define pi 3.1415926535898 
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
long long n,i,a[250005],top,sum;
struct nyh{
	long long x,id;
}o[250005];
bool cmp(nyh u,nyh v){
	return u.x>v.x;
}
bool cmp2(nyh u,nyh v){
	return u.x<v.x;
}
int main(){
    //freopen(".in","r",stdin);
    //freopen(".out","w",stdout);
   	n=read();
   	for(i=1;i<=n;i++){
		o[i].x=read();
		o[i].id=i;
	}
	sort(o+1,o+n+1,cmp);
	top=n*n;
	for(i=1;i<=n;i++){
		sum=0;
		if(a[o[i].x]!=0){
			printf("No\n");
			return 0;	
		}
		else
			a[o[i].x]=o[i].id;
		while(sum!=n-o[i].id&&top!=0){
			if(a[top]==o[i].id){
				printf("No\n");
				return 0;
			}
			if(a[top]==0){
				a[top]=o[i].id;
				sum++;
			}
			if(sum==n-o[i].id)
				break;
			top--;
		}
		if(top==0){
			printf("No\n");
			return 0;
		}
	}
	sort(o+1,o+n+1,cmp2);
	top=1;
	for(i=1;i<=n;i++){
		sum=0;
		while(sum!=o[i].id-1&&top!=0){
			if(a[top]==o[i].id){
				printf("No\n");
				return 0;
			}
			if(a[top]==0){
				a[top]=o[i].id;
				sum++;
			}
			if(sum==o[i].id-1)
				break;
			top++;
		}
		if(top==n*n+1){
			printf("No\n");
			return 0;
		}
	}
	printf("Yes\n");
	for(i=1;i<=n*n;i++)
		pus(a[i],1);
	cout<<endl;
    return 0;
}