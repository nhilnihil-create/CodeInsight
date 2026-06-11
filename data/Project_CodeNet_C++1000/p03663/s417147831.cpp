#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> PI;
inline void ask(string str){
	cout<<"? "<<str<<endl;
}
inline bool check(){
	char ch;
	cin>>ch;
	return ch=='Y';
}
inline void print_ans(string ans){
	cout<<"! "<<ans<<endl;
}
int main(){
	int l=1,r=12;
	while(r-l>1){
		int mid=(l+r)>>1;
		string str="1";
		for(int i=2;i<=mid;i++)
			str+='0';
		ask(str);
		if(check()) l=mid;
		else r=mid;
	}
	int len=l;
	if(len>10){
		l=1,r=12;
		while(l!=r){
			int mid=(l+r)>>1;
			string str;
			for(int i=1;i<=mid;i++)
				str+='9';
			ask(str);
			if(check()) r=mid;
			else l=mid+1;
		}
		len=r;
	}
	string ans;
	for(int i=1;i<=len;i++){
		if(i<len){
			l=i==1?1:0,r=10;
			while(r-l>1){
				int mid=(l+r)>>1;
				ask(ans+(char)('0'+mid));
				if(check()) l=mid;
				else r=mid;
			}
			ans+=(char)(l+'0');
		}else{
			l=i==1?1:0,r=9;
			while(l!=r){
				int mid=(l+r)>>1;
				ask(ans+(char)('0'+mid)+('0'));
				if(check()) r=mid;
				else l=mid+1;
			}
			ans+=(char)(r+'0');
		}
	}
	print_ans(ans);
	return 0;
}