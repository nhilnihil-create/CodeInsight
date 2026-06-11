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
	int a,b,c,d,e,f;
	int water;int sugar;int sugarwater;
	int maxsugarwater=-1;
	int maxsugar=-1;
	int watsug=0;
	cin >> a >> b >>c >>d>>e>>f;
	//scanf("%d %d %d %d %d %d ",&a,&b,&c,&d,&e,&f);
	
	for(int i=0;100*i*a <=f;i++)
		for(int j=0;100*b*j+100*i*a<=f;j++){
			water=100*i*a+100*b*j;
			//int k=0,l=0;
			for(int k=0;k*c<=((i*a+b*j)*e);k++)
				for(int l=0;l*d+k*c<=(i*a+b*j)*e;l++){
					
					sugar=k*c+l*d;
					if(sugar+water !=0 && sugar+water <= f){
					//sugarwater=(100*sugar)/(water+sugar);
					//printf("%d %d %d %d %d %d\n",i,j,k,l,sugarwater,sugar );
					if(sugar *(watsug) > (water+sugar)*maxsugar){
						//maxsugarwater=sugarwater;
						maxsugar=sugar;
						watsug=water+sugar;
					}
					}
				}

		}
	cout << watsug << " " <<maxsugar;

	return 0;
}	