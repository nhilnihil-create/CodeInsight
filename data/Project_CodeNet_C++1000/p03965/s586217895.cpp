#include <bits/stdc++.h>
typedef long long ll;
using namespace std;


int main()
{
	//freopen("input16.txt","r",stdin);freopen("output16.txt","w",stdout);
	ios_base::sync_with_stdio(false); cin.tie(0);
	string a;
	int i,p=0,g=0,t=0;
	cin>>a;
	for (i=0;i<a.size();i++){
		if (a[i]=='g'){
			if (g>p){
				t++;
				p++;
			}
			else {
				g++;
			}
		}
		else {
			if (g>p){
				p++;
			}
			else {
				g++;
				t--;
			}
		}
	}
	cout<<t;
	return 0;
}