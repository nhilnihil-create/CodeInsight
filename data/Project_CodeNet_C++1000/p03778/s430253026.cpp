#include<iostream>
#include<stdio.h>
#include<algorithm>
#include<vector>
#include<string.h>
#include<math.h>
#include<map>

using namespace std;

int main(){
	int w,a,b;
	cin >> w >> a >> b;
	int ans;
	if(b>a+w){
		ans=b-(a+w);
	}else if((a<=b && b <=a+w) || (a<=b+w && b+w <=a+w)){
		ans=0;
	}else{
		ans=a-(b+w);
	}
	cout << ans << endl;
	return 0;
	
}
