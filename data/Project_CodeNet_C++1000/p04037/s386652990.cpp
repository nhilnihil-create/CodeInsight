#include <iostream>
#include <algorithm>

using namespace std;
int a[100010];
int main(){
	int i,n;
	cin >> n;
	for(i=0;i<n;i++){
		cin >> a[i];
	}
	sort(a,a + n);
	int j = n - 1,k = 1;
	while(j>0 && a[j - 1]>=k + 1){
		j--; k++;
	}
	int x = a[j] - k + 1,y = 1;
	for(i=j-1;i>=0;i--){
		if(a[i]==k) y++;
	}
	if(x&1 && y&1){
		cout << "Second" << endl;
	}else{
		cout << "First" << endl;
	}
}