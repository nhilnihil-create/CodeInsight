#include<bits/stdc++.h>
using namespace std;
using ll = long long;
const auto INF = (ll)1e9;
using v = vector<ll>;
using p = pair<ll,ll>;
using m = map<ll,ll>;
using vv = vector<v>;
int gcd(int a,int b){
    return a==0? b :gcd(a,a%b);
}


int main(){
    ll h,w;
    cin >> h >> w;
    ll diff =INF;
    for (int i = 1; i < h; i++)
    {
        ll a,b,c;
        a = i*w;
        b = (h-i)/2*w;
        c = (h-i)*w-b;
        diff = min(diff,max({a,b,c})-min({a,b,c}));
      	//cout << a << " " << b << " "<<c << endl;
      	b = w/2*(h-i);
      	c = (w-w/2)*(h-i);
      	diff = min(diff,max({a,b,c})-min({a,b,c}));
      	//cout << a << " " << b << " "<<c << endl;
    }
  	//cout << endl;
  	for (int i = 1; i < w; i++)
    {
        ll a,b,c;
        a = i*h;
        b = (w-i)/2*h;
        c = (w-i)*h-b;
        diff = min(diff,max({a,b,c})-min({a,b,c}));
      	//cout << a << " " << b << " "<<c << endl;
      	b = h/2*(w-i);
      	c = (h-h/2)*(w-i);
      	diff = min(diff,max({a,b,c})-min({a,b,c}));
      	//cout << a << " " << b << " "<<c << endl;
    }
  
    cout << diff<<endl;
    return 0;
}
