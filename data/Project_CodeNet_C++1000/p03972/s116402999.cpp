#include <iostream>
#include<vector>
#include<algorithm>
using namespace std;

int main() {
	int w,h;cin>>w>>h;
	vector<long long> p(w),q(h);
	for(int i=0;i<w;i++)cin>>p[i];
	for(int i=0;i<h;i++)cin>>q[i];
	sort(p.begin(),p.end());
	sort(q.begin(),q.end());
	int pi=0;
	int qi=0;
	long long ans=0;
	while(1){
		if(pi==w){
			if(qi==h){
				break;
			}
		}
		if(pi==w){
			ans+=q[qi];
			qi++;
		}else if(qi==h){
			ans+=p[pi];
			pi++;
		}else if(p[pi]<q[qi]){
			ans+=(h+1-qi)*p[pi];
			pi++;
		}else{
			ans+=(w+1-pi)*q[qi];
			qi++;
		}
	}
	cout<<ans<<endl;
	return 0;
}
