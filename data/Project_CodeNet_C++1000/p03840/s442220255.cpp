#include<stdio.h>
#include<string.h>
#include<time.h>
#include<math.h>
#include<stdlib.h>
#include<iostream>
#include<iomanip>
#include<utility>
#include<algorithm>
#include<stack>
#include<queue>
#include<map>
#include<set>
#define ll long long
#define fi first
#define sec second
#define pb push_back
#define mp make_pair
#define rep(a,b,c) for(int a=1;a<=b;a+=c)
#define repp(a,b,c,d) for(int a=b;a<=c;a+=d)

const double PI=acos(-1);
const double EPS=1e-12;
const int MOD=1e9+7;
const int INF=1<<30;


using namespace std;


int main(){
	//ios::sync_with_stdio(false);cin.tie(NULL);	cout.tie(NULL);
	ll res=0,ans=0;
	ll t,I,O,T,J,L,S,Z;
	cin>>I>>O>>T>>J>>L>>S>>Z;
	t=(J%2)+(L%2)+(I%2);
	if(t>=2&&J!=0&&L!=0&&I!=0){
		res+=3;
		J--;
		L--;
		I--;
	}
	res+=O;
	res+=(I/2)*2;
	res+=(J/2)*2;
	res+=(L/2)*2;
	cout<<res<<endl;
	return 0;
}

