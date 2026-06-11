#include<bits/stdc++.h>

using namespace std;
using ll = long long;

ll h, w, ans = 1e9, a, b, c, ma, mi, p, q;

int main(){
	cin >> h >> w;
	
	for(ll i = 1; i < w; ++i){
		a = h*i, b = (w-i)*(h-h/2), c = (w-i)*(h/2);
		ma = max(a, max(b, c)), mi = min(a, min(b, c));
		ans = min(ans, ma-mi);
	}
	
	for(ll i = 1; i < h; ++i){
		a = w*i, b = (h-i)*(w-w/2), c = (h-i)*(w/2);
		ma = max(a, max(b, c)), mi = min(a, min(b, c));
		ans = min(ans, ma-mi);
	}
	
	for(ll i = 1; i < w; ++i){
		a = h*i, b = h*((w-i)/2), c = h*(w-i-((w-i)/2));
		ma = max(a, max(b, c)), mi = min(a, min(b, c));
		ans = min(ans, ma-mi);
	}
	
	for(ll i = 1; i < h; ++i){
		a = w*i, b = w*((h-i)/2), c = w*(h-i-((h-i)/2));
		ma = max(a, max(b, c)), mi = min(a, min(b, c));
		ans = min(ans, ma-mi);
	}
	
	cout << ans << endl;
}
