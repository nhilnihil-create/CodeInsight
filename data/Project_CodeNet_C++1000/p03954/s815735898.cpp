#include <bits/stdc++.h>
using namespace std;
const int MAX=4e5+10;
template <typename T> inline  void read(T &a){
      T w=1;a=0;
	  char ch=getchar();
	  for(;!isdigit(ch);ch=getchar()){
	      if(ch == '-') w=-1;
	  }
	  for(;isdigit(ch);ch=getchar()){
	      a=(a<<3)+(a<<1)+(ch^48);
	  }
	  a*=w;
}
int n;
int a[MAX];

int ck(int k){
    for(register int i=0;i<n;++i){
	    if((a[n+i] <= k && a[n+i+1]<=k) || (a[n-i]<=k && a[n-i-1]<=k)) return 1;
		if((a[n+i]>k && a[n+i+1]>k) || (a[n-i]>k && a[n-i-1]>k)) return 0;
	}
	return a[1]<=k;
}

int main(){
		read(n);
		for(register int i=1;i<(n*2);++i){
		    read(a[i]);
		}
	    int l=1,r=(n<<1)-1;
		while(l<r){
		   int mid=(l+r)>>1;
		   if(ck(mid)) r=mid;
		   else l=mid+1;
		}
		cout<<l;

}