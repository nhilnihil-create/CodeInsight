#include<iostream>
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef vector<int> vi;
typedef pair<int,int> pi;

#define F first
#define S second
#define PB push_back
#define MP make_pair
#define what_is(x) cerr << #x << " is " << x << endl;
#define MT make_tuple
#define eb emplace_back
#define rep(i, begin, end) for (__typeof(end) i = (begin) - ((begin) > (end)); i != (end) - ((begin) > (end)); i += 1 - 2 * ((begin) > (end)))

#define REP(i,a,b) for (int i = a; i <= b; i++)
#define FOR(i,n) for (int i=0;i < n ; i++)
#define error(args...) { string _s = #args; replace(_s.begin(), _s.end(), ',', ' '); stringstream _ss(_s); istream_iterator<string> _it(_ss); err(_it, args); }

void err(istream_iterator<string> it) {}
template<typename T, typename... Args>
void err(istream_iterator<string> it, T a, Args... args) {
	cerr << *it << " = " << a << endl;
	err(++it, args...);
}



int main(){
	ll n;
	ll a;
	cin >> n >> a;
	ll x[n];
	FOR(i,n)cin >>x[i];
	ll array[n][n*a+1][n+1];
	//FOR(i,20) cout <<i%10 <<" ";
	//cout <<"\n";
	FOR(i,n)
		FOR(j,n*a+1)
			FOR(w,n+1)
				array[i][j][w]=0;
	FOR(i,n) 
		FOR(t,a+1)
			array[i][t][0]=(t==0) ? 1:0 ;
	//cout << array[1][0][0];
	FOR(i,n)
		FOR(t,n*a+1)
			for(int k=1; k < n+1;k++)
				{
					if(i!=0){
						if(t >=x[i]) 
							array[i][t][k]=array[i-1][t-x[i]][k-1] + array[i-1][t][k];
						else
							array[i][t][k]=array[i-1][t][k];
					}
					else{ 
						//if(k==0) array[i][t][k]=(t==0)? 1: 0;
						if(k==1) array[i][t][k]=(t==x[0])?1:0;
						else array[i][t][k]=0;
					}				
				}
	ll count=0;

	for(int k=1; k<n+1;k++){
		count+=array[n-1][k*a][k];
		//cout << k<<" : "<<array[n-1][k*a][k]<<"\n";
	}
	cout <<count;

	return 0;
}