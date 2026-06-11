#include<bits/stdc++.h>
#define mo 1000000007
#define pi 3.1415926535898
#define eps 1e-9 
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
long long i,l,r,mid,min1,y;
char s[15];
void query(long long x){
	printf("? %lld\n",x);
	fflush(stdout);
	scanf("%s",s);
}
int main(){
	//freopen("camp.in","r",stdin);
	//freopen("camp.out","w",stdout);
	y=1000000000;
	query(y);
	if(s[0]=='Y'){
		i=9;
        while(i){
            query(y-1);
            if(s[0]!='Y')
            	break;
            y/=10;
            i--;
        }
        cout<<"! "<<y<<endl;
        return 0;
    }
	for(i=1;;i=i*10){
		query(i);
		if(s[0]=='N'){
			i/=10;
			l=i;
			r=i*10-1;
			mid=(l+r)/2;
			break;
		}
	}
	min1=r+1;
	while(l<=r){
		query(mid*10);
		if(s[0]=='Y'){
			min1=min(min1,mid);
			r=mid-1;
		}
		else
			l=mid+1;
		mid=(l+r)/2;
	}
	cout<<"! "<<min1<<endl;
	return 0;
}