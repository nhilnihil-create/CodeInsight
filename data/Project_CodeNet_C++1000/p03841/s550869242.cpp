#include <cstdio>
#include <cstdlib>
#include <iostream>
#include <fstream>
#include <sstream>
#include <set>
#include <map>
#include <vector>
#include <list>
#include <algorithm>
#include <cstring>
#include <cmath>
#include <string>
#include <queue>
#include <bitset>     //UWAGA - w czasie kompilacji musi byc znany rozmiar wektora - nie mozna go zmienic
#include <cassert>
#include <iomanip>        //do setprecision
#include <ctime>
#include <complex>
using namespace std;

#define FOR(i,b,e) for(int i=(b);i<(e);++i)
#define FORQ(i,b,e) for(int i=(b);i<=(e);++i)
#define FORD(i,b,e) for(int i=(b)-1;i>=(e);--i)
#define REP(x, n) for(int x = 0; x < (n); ++x)

#define ST first
#define ND second
#define PB push_back
#define MP make_pair
#define LL long long
#define ULL unsigned LL
#define LD long double

const double pi = 3.141592653589793238462643383279502884197169399375105820974944592307816406286208998628034825342;
const int mod=1000000007;

int main(){
	int n;
	cin>>n;
	vector<int> x(n+1,0),ans(n*(n+1),0),th(n+1,0);
	priority_queue<pair<int,int>> pq;
	priority_queue<pair<int,int>> pq2;
	FORQ(i,1,n){
		cin>>x[i];
		pq.push(MP(-x[i],i));
		pq2.push(MP(x[i],i));
		th[i]=x[i];
	}
	int l=1,r=n*n;
	while(pq.size()){
		pair<int,int> pr=pq.top();
		pq.pop();
		int tm=-pr.ST,num=pr.ND;
		FORQ(i,1,num){
			while(ans[l]!=0){
				l++;
			}
			if(i==num){
				if(ans[tm]!=0){
					cout<<"No"<<endl;
					return 0;
				}
				ans[tm]=num;
				if(l==tm)l++;
				break;
			}
			ans[l]=num;
			l++;
		}
	}
	while(pq2.size()){
		pair<int,int> pr=pq2.top();
		pq2.pop();
		int tm=pr.ST,num=pr.ND;
		FORQ(i,1,n-num){
			while(ans[r]!=0){
				r--;
			}
			ans[r]=num;
			r--;
			if(i==n-num){
				if(tm>r){
					cout<<"No"<<endl;
					return 0;
				}
				break;
			}
		}
	}

	cout<<"Yes"<<endl;
	FOR(i,1,n*n){
		cout<<ans[i]<<" ";
	}
	cout<<ans[n*n]<<endl;
    return 0;
}
