#include<bits/stdc++.h>
#define getchar() (p1==p2&&(p2=(p1=buf)+fread(buf,1,1<<21,stdin),p1==p2)?EOF:*p1++)
char buf[1<<21],*p1=buf,*p2=buf;

using namespace std;
const int N=1e5+10;
int T,n,j,ans,a[N];

inline int read(){
    int ret=0,ff=1;char ch=getchar();
    while(!isdigit(ch)){if(ch=='-') ff=-ff;ch=getchar();}
    while(isdigit(ch)){ret=(ret<<3)+(ret<<1)+ch-'0';ch=getchar();}
    return ret*ff;
}
void write(int x){
    if(x<0){x=-x;putchar('-');}
    if(x>9) write(x/10);
    putchar(x%10+48);
}

int main(){

	    scanf("%d",&n);
	    for (register int i=1; i<=n; ++i) scanf("%d",&a[i]);
	    sort(a+1,a+n+1);
		reverse(a+1,a+n+1);	 
	    for (register int i=1; i<=n; ++i)
	    if (i+1>a[i+1])
		{
		//	printf("%d\n",i);
	    	j=i+1,ans=0; 
			while (a[j]==i) ans++,j++;
			if (ans%2==1 || (a[i]-i)%2==1) puts("First");
			else puts("Second");
			break;
	    }
}