#include <iostream>
#include <string>
using namespace std;

int main() {
	string ans="";
	int now=0;
	while(ans.size()<10){
		int l=-1, r=9;
		if(ans.size()<1) l=0;
		while(l+1<r){
			string n=ans;
			int mid=(l+r)/2;
			n += ('0'+mid);
			while(n.size()<18) n += '9';
			cout << "? " << n << endl;
			char res;
			cin >> res;
			if(res=='Y') r=mid;
			else l=mid;
		}
		ans += ('0'+r);
	}//40
	int l2=9, r2=10;
	while(ans[l2]=='0') --l2;
	int basl2=l2;
	//cout << basl2 << endl;
	while(l2+1<r2){
		int mid2=(l2+r2)/2;
		//cout << mid2 << endl;
		string ask=ans.substr(0, mid2);
		bool sunao=true;
		if(mid2==basl2+1){
			if(ask=="1"){
				ask="2";
			}else{
				ask[0]='1';
				for(int i=1; i<ask.size(); ++i){
					ask[i]='0';
				}
				ask += '0';
				sunao=false;
			}
		}else{
			ask.back()='9';
		}
		cout << "? " << ask << endl;
		char res2;
		cin >> res2;
		if((res2=='Y')^(!sunao)) r2=mid2;
		else l2=mid2;
	}
	cout << "! " << ans.substr(0, r2) << endl;
	return 0;
}