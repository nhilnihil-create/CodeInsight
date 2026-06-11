#include <iostream>
#include <iomanip>
#include <sstream>
#include <vector>
#include <string>
#include <set>
#include <map>
#include <stack>
#include <queue>
#include <deque>
#include <algorithm>
#include <functional>
#include <iterator>
#include <limits>
#include <numeric>
#include <utility>
#include <cmath>
#include <cassert>
#include <cstdio>

// #include <unordered_set>
// #include <unordered_map>

#define rep(i, a, n) for(int i = a; i < n; i++)
#define REP(i, n) rep(i, 0, n)
#define repb(i, a, b) for(int i = a; i >= b; i--)
#define all(a) a.begin(), a.end()
#define SORT(c) sort((c).begin(),(c).end())
#define RSORT(c) sort((c).rbegin(),(c).rend())

#define pb push_back
#define mp make_pair

int gcd(int a,int b){int c;while(b!=0){c=a%b;a=b;b=c;}return a;}
int lcm(int a,int b){int c=gcd(a,b);a/=c;return a*b;}

typedef std::pair<int, int> P;
typedef long long ll;
typedef long double ld;

const int MOD = 1000000007;
const int INF = 1e9;
const ll LINF = INF * 1ll * INF;
const ld DINF = 1e200;
const double EPS = 1e-10;
const double PI  = acos(-1.0);

using namespace std;

#define int long long

const int MAX_V=1000;
int dist[MAX_V][MAX_V];
int n,m;
bool out=false;
bool use[MAX_V][MAX_V];


void init(int n){
	REP(i,n){
		REP(j,n){
			use[i][j]=true;
		}
	}
}
 
void hoge_warshall_floyd(int V){
    for(int k=0;k<V;k++){
        for(int i=0;i<V;i++){
            for(int j=0;j<V;j++){
            	// dist[i][j]=min(dist[i][j],dist[i][k]+dist[k][j]);
            	if(dist[i][j]>dist[i][k]+dist[k][j]){
            		out=true;
            	}
            }
        }
    }
}
 
 
signed main(){



	
    
    cin>>n;
    init(n);
    int hoge;
 
//init
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            if(j==i)dist[i][j]=0;
            else dist[i][j]=INF;
        }
    }
 
    for(int i=0;i<n;i++){
    	for(int j=0;j<n;j++){
    		cin>>hoge;
    		dist[i][j]=hoge;
    	}  
    }

 
    hoge_warshall_floyd(n);

    if(out){
    	cout<<-1<<endl;
    	return 0;
    }


    int sum=0;

    REP(i,n){
    	REP(j,n){
    		sum+=dist[i][j];
    	}
    }


    REP(i,n){
    	REP(j,n){
    		REP(k,n){

    			if(k==i||k==j)continue;
    			if(dist[i][j]<dist[i][k]+dist[k][j])continue;
    			use[i][j]=false;
    			break;
    		}
    	}
    }

   // REP(i,n){
   // 		REP(j,n){
			// cout<<use[i][j]<<" ";
   // 		}cout<<endl;
   // }


   REP(i,n){
   	REP(j,n){
   		if(!use[i][j]){
   			sum-=dist[i][j];
   		}
   	}
   }
    cout<<sum/2<<endl;
      
    return 0;
}