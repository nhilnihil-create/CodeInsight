#include<bits/stdc++.h>
using namespace std;
template<class t> inline t read(t &x){
    char c=getchar();bool f=0;x=0;
    while(!isdigit(c)) f|=c=='-',c=getchar();
    while(isdigit(c)) x=(x<<1)+(x<<3)+(c^48),c=getchar();
    if(f) x=-x;return x;
}
template<class t> inline void write(t x){
    if(x<0) putchar('-'),write(-x);
    else{if(x>9) write(x/10);putchar('0'+x%10);}
}
template<class t> inline void writeln(t x){
	write(x),putchar('\n');
	return;
}
/*int check(int j){
	if(a[j]>=a[j+1] && a[j]<=a[j+2]){
		return a[j];
	}
	if(a[j]>=a[j+2] && a[j]<=a[j+1]){
		return a[j];
	}
	if(a[j+1]>=a[j] && a[j+1]<=a[j+2]){
		return a[j+1];
	}
	if(a[j+1]>=a[j+2] && a[j+1]<=a[j]){
		return a[j+1];
	}
	if(a[j+2]>=a[j+1] && a[j+2]<=a[j]){
		return a[j+2];
	}
	if(a[j+2]>=a[j] && a[j+2]<=a[j+1]){
		return a[j+2];
	}
}*/
int l,r,mid,a[200010],n;
bool f[200010];
bool check(int num){
	for(int i=1;i<=2*n-1;i++){
		if(a[i]>num){
			f[i]=1;
		}else{
			f[i]=0;
		}
	}
	for(int i=1;i<=n-1;i++){
		if(f[n+i]==f[n+i-1] && f[n+i]!=0){
			return 0;
		}
		if(f[n+i]==f[n+i-1] && f[n+i]==0){
			return 1;
		}
		if(f[n-i]==f[n-i+1] && f[n-i]!=0){
			return 0;
		}
		if(f[n-i]==f[n-i+1] && f[n-i]==0){
			return 1;
		}
	}
	return f[n]^(n&1);
}
int main(){
  //  freopen("pyramid.in","r",stdin);
//	freopen("pyramid.out","w",stdout);
	read(n);
	for(int i=1;i<=2*n-1;i++){
		read(a[i]);
	}
	r=2*n-1;
	while(l<r){
		mid=(l+r)/2;
		if(check(mid)==0){
			l=mid+1;
		}else{
			r=mid;
		}
	}
	write(l);
	/*
	for(int i=1;i<=2*n-1;i++){
		if(a[i]==1 || a[i]==0){
			pd=0;
		}else{
			pd=1;
			break;
		}
	}
	if(pd==0){
		if(a[n-1]==a[n] || a[n]==a[n+1]){
			cout<<a[n];
			return 0;
		}
		else{
			for(int i=1;i<=2*n-3;i++){
				f[i]=check(i);
			}
			int num0=0,num1=0;
			for(int i=1;i<=2*n-3;i++){
				if(f[i]==1){
					num1++;
				}else{
					num0++;
				}
			}
			if(num1>num0){
				cout<<"1";
				return 0;
			}else{
				cout<<"0";
				return 0;
			}
		}
	}else{
		int s=n;
		int mid;
		for(int i=1;i<=2*s-1;i++){
			if(s==1){
				break;
			}
			for(int j=1;j<=2*s-3;j++){
				f[i]=check(j);
			}
			s-=2;
			for(int j=1;j<=2*s-1;j++){
				a[i]=f[i];
			}
		}
		write(f[1]);
	}*/
    return 0;
}