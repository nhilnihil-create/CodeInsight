#include <iostream>
using namespace std;

int N;
int main(){
	cin >> N;
	long long ans = 0,val = 1,a;
	for(int i=0;i<N;i++){
		cin >> a;
		if(val<a){
			if(val==1){
				val++;
				ans += a-1;
			}else{
				ans += a/val;
				if(a%val==0) ans--;
			}
		}else{
			val = max(a+1,val);
		}
	}
	cout << ans << endl;
}