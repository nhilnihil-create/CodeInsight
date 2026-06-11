#include<bits/stdc++.h>

using namespace std;
typedef long long int ll;

int n, l, t, sh = 0;
vector <int> p;

int main()
{
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	cin >> n >> l >> t;
	for(int i = 0; i < n; i++){
		int x, ty;
		cin >> x >> ty;
		if(ty == 1){
			p.push_back((x + t) % l);
			sh += ((x + t) / l);
		//	cout << "+" << ((x + t) / l) << '\n';
		}
		else{
			p.push_back((((x - t) % l) + l) % l);
			x = l - x;
			sh -= ((x + t - 1) / l);
		//	cout << "-" <<  ((x + t - 1) / l) << '\n';
		}
		//cout << "sh:" << sh << '\n';
	}
	sort(p.begin(), p.end());
	sh %= n; sh += n; sh %= n;
	for(int i = sh; i < n; i++)
		cout << p[i] << endl;
	for(int i = 0; i < sh; i++)
		cout << p[i] << endl;
	//cout << "sh: " << sh << endl;
	return 0; 
}
