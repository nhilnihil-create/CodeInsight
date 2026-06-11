#include<algorithm>
#include<iostream>
using namespace std;
int a[100035],n,l,t,x,cnt;
int main(){
	cin>>n>>l>>t;
    for(int i=1;i<=n;i++){
    	cin>>a[i]>>x;
        a[i]+=((x==1)?t:-t);
        cnt+=a[i]/l;
        if(a[i]%l<0){
			cnt--;
		}
        ((a[i]%=l)+=l)%=l;
    }
    sort(a+1,a+n+1);
    ((cnt%=n)+=n)%=n;
    for(int i=cnt+1;i<=n;i++){
    	cout<<a[i]<<endl;
    }
    for(int i=1;i<=cnt;i++){
    	cout<<a[i]<<endl;
    }
    return 0;
}