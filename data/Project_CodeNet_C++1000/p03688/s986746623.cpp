#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main(){
	ios_base::sync_with_stdio(false);cin.tie(NULL);
	int n;cin>>n;
	vector<int>v;
	int mn=1e9,mx=0;
	int cnt_mn=0,cnt_mx=0;
	for(int i=0;i<n;i++){
		int a;cin>>a;v.push_back(a);
		mn=min(a,mn);mx=max(mx,a);
	}
	for(int i=0;i<n;i++){
		if(v[i]==mn)cnt_mn++;
		if(v[i]==mx)cnt_mx++;
	}
	if(mx-mn>1){
		cout<<"No"<<endl;
		return 0;
	}
	if(mx!=mn&&cnt_mn<=mn&&cnt_mx>1&&(cnt_mn>=mx-1||(cnt_mx>=4&&cnt_mn+(cnt_mx-2)/2>=mx-1))){
		cout<<"Yes"<<endl;
	}else{
		if(mx==mn&&((mx==1||mn==n-1)||(mx*2<=n)))cout<<"Yes"<<endl;
		else cout<<"No"<<endl;
	}
	
	return 0;
}