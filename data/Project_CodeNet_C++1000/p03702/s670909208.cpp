#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int N, A, B, h[100000];

int search(void){
	int Min = -1, Max = 1000000000;
	while(Max > Min+1){
		ll m = (Min + Max)/2, flag = 0, cnt = 0;
		for(int i=0; i<N; i++){
			ll t = (h[i] - m*B + A - B - 1)/(A-B);
		    t = (t>0?t:0);
            cnt += t;
        }
		if(cnt <= m) Max = m;
		else Min = m;
	}
	return Max;
}

int main(){
	cin >> N >> A >> B;
	for(int i=0; i<N; i++) cin >> h[i];
	int ans = search();
	cout << ans << endl;
	return 0;
}
