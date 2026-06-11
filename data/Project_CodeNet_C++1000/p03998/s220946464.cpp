#include<bits/stdc++.h>
using namespace std;
using lli = long long;
#define rep(i,n) for(int i=0;i<n;i++)

int main(void){
	string sa, sb, sc;
	cin >> sa >> sb >> sc;
	lli i = 0, j = 0, k = 0;
	char t = 'a';
	char ans;
	while(1){
		if(t == 'a'){
			if(i == sa.size()){
				ans = 'A';
				break;
			}
			t = sa[i];
			i++;
		}else if(t == 'b'){
			if(j == sb.size()){
				ans = 'B';
				break;
			}
			t = sb[j];
			j++;
		}else if(t == 'c'){
			if(k == sc.size()){
				ans = 'C';
				break;
			}
			t = sc[k];
			k++;
		}
	}
	cout << ans << endl;
	return 0;
}
