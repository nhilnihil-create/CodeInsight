#include <iostream>
#include <vector>
#include <set>
#include <algorithm>
#include <fstream>
#include <string>
#include <math.h>
#include <cstdlib>
#include <cstdint>
#include <istream>
#include <sstream>
#include <cctype>
#include <functional>
#include <iomanip>
#define fore(i,x,y) for(ll i=(x);i<(y);i++)
#define disp(a) cout << a << endl;
#define PI 3.14159265359
typedef long long ll;
using namespace std;
int main()
{
	ll N,M,tmp;
	vector<ll>vecx;
	vector<ll>vecy;
	vector<ll>veccx;
	vector<ll>veccy;
	cin>>N>>M;
	fore(i,0,N){
		ll x,y;
		cin>>x>>y;
		vecx.push_back(x);
		vecy.push_back(y);
	}
	fore(i,0,M){
		ll x,y;
		cin>>x>>y;
		veccx.push_back(x);
		veccy.push_back(y);
	}
	fore(i,0,N){
		ll min=0,minp=1000000000;
		fore(j,0,M){
			tmp=abs(vecx[i]-veccx[j])+abs(vecy[i]-veccy[j]);
			//cout<<tmp<<endl;
			if(minp>tmp){
				min=j+1;
				minp=tmp;
			}
		}
		cout<<min<<endl;
	}

}