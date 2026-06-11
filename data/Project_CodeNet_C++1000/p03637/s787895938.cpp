#include<iostream>
#include<algorithm>
#include<vector>
#include<string.h>
#include<math.h>
#include<map>

using namespace std;
	
int main(){
	int n;
	cin >> n;
	vector<long long> a(n);
	
	int cnt_4=0,cnt_KI=0,cnt_GU=0;
	
	for(int i=0;i<n;i++){
		cin >> a[i];
		if(a[i]%4==0){
			cnt_4++;
			continue;
		}
		if(a[i]%2!=0){
			cnt_KI++;
			continue;
		}
		if(a[i]%2==0){
			cnt_GU++;
		}
	}
	
	if(cnt_GU == 0){
		if(cnt_KI-cnt_4<=1){
			cout << "Yes" <<endl;
		}else{
			cout << "No" << endl;
		}
	}else if(cnt_GU != 0){
		if(cnt_KI-cnt_4<=0){
			cout << "Yes" <<endl;
		}else{
			cout << "No" << endl;
		}
	}
	
	return 0;
}
