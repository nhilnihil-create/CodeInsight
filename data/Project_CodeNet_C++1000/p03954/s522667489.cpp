#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;
#define mp make_pair
#define PI pair<int,int>
#define poly vector<int>
#define For(i,l,r) for(int i=(int)(l);i<=(int)(r);i++)
#define Rep(i,r,l) for(int i=(int)(r);i>=(int)(l);i--)
#define pb push_back
#define mem(a) memset((a),0,sizeof(a))
#define fi first
#define se second
inline char gc(){
    static char buf[100000],*p1=buf,*p2=buf;
    return p1==p2&&(p2=(p1=buf)+fread(buf,1,100000,stdin),p1==p2)?EOF:*p1++;
}
#define gc getchar
inline ll read(){
	ll x = 0; char ch = gc(); bool positive = 1;
	for (; !isdigit(ch); ch = gc())	if (ch == '-')	positive = 0;
	for (; isdigit(ch); ch = gc())	x = x * 10 + ch - '0';
	return positive ? x : -x;
}
inline void write(ll a){
    if(a<0){
    	a=-a; putchar('-');
	}
    if(a>=10)write(a/10);
    putchar('0'+a%10);
}
inline void writeln(ll a){write(a); puts("");}
inline void wri(ll a){write(a); putchar(' ');}
int n,nl[2000010];
int check(int k){
    for(int i=0;i<n-1;i++){//哪对1和0离中间最近，最上面就是什么数 
        if((nl[n+i]>k && nl[n+i+1]>k)
		|| (nl[n-i]>k && nl[n-i-1]>k)){//求是否都大于
        	return 1;
		}
        if((nl[n+i]<=k && nl[n+i+1]<=k)
		|| (nl[n-i]<=k && nl[n-i-1]<=k)){//求是否都小于等于
        	return 0;
		}
    }
    return nl[1]<=k?0:1;
}
int main(){
//	freopen("pyramid.in","r",stdin);
//	freopen("pyramid.out","w",stdout);
    cin>>n;
    int js0=0,js1=0;
    for(int i=1;i<=2*n-1;i++){
    	nl[i]=read();
    	if(nl[i]==0) js0++;
    	if(nl[i]==1) js1++;
	}
    if(js0+js1!=n*2-1){
    	int l=1,r=2*n-1,ans,mid;
	    while(l<r){
	        mid=(l+r)>>1;
	        if(check(mid)==0) r=mid;
	        else l=mid+1;
	    }
	    cout<<l<<endl;
	}
	else{
		for(int i=0;i<n-1;i++){//哪对1和0离中间最近，最上面就是什么数 
	        if((nl[n+i]==1 && nl[n+i+1]==1)
			|| (nl[n-i]==1 && nl[n-i-1]==1)){
				
				cout<<"1"<<endl;
	        	return 0;
			}
	        if((nl[n+i]==0 && nl[n+i+1]==0)
			|| (nl[n-i]==0 && nl[n-i-1]==0)){
				cout<<"0"<<endl;
	        	return 0;
			}
    	}
    	printf("%d\n",nl[1]==0?0:1);
	}
    return 0; 
}