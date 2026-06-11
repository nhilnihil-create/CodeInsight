#include <iostream>
#define llint long long

using namespace std;

llint n;
llint a[100005];

llint gcd(llint a, llint b){
	if(b == 0) return a;
	return gcd(b, a%b);
}

bool calc()
{
	llint cnt = 0, sum = 0;
	for(int i = 1; i <= n; i++) if(a[i] % 2) cnt++;
	for(int i = 1; i <= n; i++) sum += a[i] - 1;
	
	if(cnt == 1 && sum % 2 == 0){
		llint d = 0;
		for(int i = 1; i <= n; i++){
			if(a[i] % 2){
				if(a[i] == 1) return false;
				a[i]--;
				break;
			}
		}
		for(int i = 1; i <= n; i++) d = gcd(d, a[i]);
		if(d > 1){
			for(int i = 1; i <= n; i++) a[i] /= d;
			return !calc();
		}
	}
	return sum % 2;
}

int main(void)
{
	cin >> n;
	for(int i = 1; i <= n; i++) cin >> a[i];
	
	if(calc()) cout << "First" << endl;
	else cout << "Second" << endl;
	return 0;
}