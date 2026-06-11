#include <stdio.h>
#include <algorithm>
using namespace std;

int n;
long long l;
long long t;
long long a[100002];
long long w[100002];
long long p[100002];
int np;
long long q[100002];
int nq;
long long tmpnum;
long long zero;

int i;
int num;
long long pos;
long long first_ant;
long long tmpnum2;

int main(){
	scanf("%d%lld%lld",&n,&l,&t);
	for(i=0;i<n;i++){
		scanf("%lld%d",&a[i],&w[i]);
		if(w[i]==1){
			p[np++] = a[i];
			if(np==1){
				tmpnum = i;
				tmpnum2 = nq;
				
			}
		}
		else{
			q[nq++] = a[i];
		}
		
	}
	if(np>0){
		num=tmpnum+((2*t)/l)*nq;
		num%=n;
		pos=(p[0]+2*t)%l;
		zero=t%l;
	
		//find num
		bool tick = 0;
		if(nq>0){
			for(i=0;i<nq;i++){
				if(pos<=q[i]){
					if(i>=tmpnum2){
						num+=i-tmpnum2+n;
						num%=n;
					}
					else{
						num+=nq+i-tmpnum2+n;
						num%=n;
					}
					tick = 1;
					break;
				}
			}
			if(!tick){
				num+=nq-tmpnum2+n;
				num%=n;
			}
		}
		
		pos = (p[0]+t)%l;
		for(i=0;i<n;i++){
			if(w[i]==1) a[i] = (a[i]+2*t)%l;
			a[i] = (a[i]-zero+l)%l;
		}
		sort(a,a+n);
		for(i=0;i<n;i++){
			if(pos==a[i]){
				first_ant = (i-num+n)%n;
				break;
			}
		}
		for(i=first_ant;i<n;i++){
			printf("%lld\n",a[i]);
		}
		for(i=0;i<first_ant;i++) printf("%lld\n",a[i]);
	}
	else{
		for(i=0;i<n;i++){
			printf("%lld\n",(((a[i]-t)%l)+l)%l);
		}
	}

	
	return 0;
}