#include<cstdio>
#include<cstring>
#include<algorithm>
#include<iostream>
#include<cmath>
#include<stack>
#include<queue>
using namespace std;
typedef long long ll;

ll h,w,ma,mi,ans;
ll S1,S2,S3; 

ll read(){ ll s=0,f=1; char ch=getchar(); while(ch<'0' || ch>'9'){ if(ch=='-') f=-1; ch=getchar(); } while(ch>='0' && ch<='9'){ s=s*10+ch-'0'; ch=getchar(); } return s*f; }

int main(){
	ans = 1e15-1;
	h = read() ,w = read();
	
//	if(h<w){ swap(h,w); }
	
//	printf("%lld %lld\n",h,w);
	
	for(ll i = 1;i < h; i++){
		S1 = i * w;
		mi = S1 , ma = S1;
		if(w%2==1){
			S2 = (w / 2ll) * (h - i) * 1ll;
			S3 = ((w / 2ll) + 1ll) * (h - i) * 1ll;
			ma = max(ma,S2); mi = min(mi,S2);
			ma = max(ma,S3); mi = min(mi,S3);
		}else if(w%2==0){
			S2 = (w / 2ll) * (h - i);
			ma = max(ma,S2); mi = min(mi,S2);
		}
		ans = min(ans,ma - mi);
	}
//	printf("%lld\n",ans);
	
	for(ll i = 1;i < w; i++){
		S1 = i * h;
		mi = S1 , ma = S1;
		if(h%2==1){
			S2 = (h / 2ll) * (w - i) * 1ll;
			S3 = ((h / 2ll) + 1ll) * (w - i) * 1ll;
			ma = max(ma,S2); mi = min(mi,S2);
			ma = max(ma,S3); mi = min(mi,S3);
		}else if(h%2==0){
			S2 = (h / 2ll) * (w - i);
			ma = max(ma,S2); mi = min(mi,S2);
		}
		ans = min(ans,ma - mi);
	}
//	printf("%lld\n",ans);
	
	for(ll i = 1;i < h-1; i++){
		S1 = i * w;
		mi = S1 , ma = S1;
		if((h-i)%2==1){
			S2 = ((h-i) / 2ll) * w * 1ll;
			S3 = (((h-i) / 2ll) + 1ll) * w * 1ll;
			ma = max(ma,S2); mi = min(mi,S2);
			ma = max(ma,S3); mi = min(mi,S3);
		}else if((h-i)%2==0){
			S2 = ((h-i) / 2ll) * w;
			ma = max(ma,S2); mi = min(mi,S2);
		}
		ans = min(ans,ma - mi);
	}
//	printf("%lld\n",ans);
	
	for(ll i = 1;i < w-1; i++){
		S1 = i * h;
		mi = S1 , ma = S1;
		if((w-i)%2==1){
			S2 = ((w-i) / 2ll) * h * 1ll;
			S3 = (((w-i) / 2ll) + 1ll) * h * 1ll;
			ma = max(ma,S2); mi = min(mi,S2);
			ma = max(ma,S3); mi = min(mi,S3);
		}else if((w-i)%2==0){
			S2 = ((w-i) / 2ll) * h;
			ma = max(ma,S2); mi = min(mi,S2);
		}
		ans = min(ans,ma - mi);
	}
//	printf("%lld\n",ans);
	
	printf("%lld\n",ans);

	return 0;
}