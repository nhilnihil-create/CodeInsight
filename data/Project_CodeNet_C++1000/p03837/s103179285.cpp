#include <bits/stdc++.h>

using namespace std;
 
#define IOS		    ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
#define ld 		    long double
#define ll 		    long long int
#define ull 	   	    unsigned long long int
#define pb		    push_back
#define mp		    make_pair
#define F		    first
#define S		    second
#define lb		    lower_bound
#define ub		    upper_bound
#define deb(x)      	    cout<<"#x "<<x<<"\n";
#define trace(x,y)  	    cout<<"#x "<<x<<" #y "<<y<<"\n";
#define cn          	    cout<<"\n";


bool SBF(const pair <int,int>& a, const pair<int,int>& b){return a.F<b.F;}
bool SBS(const pair <int,int>& a, const pair<int,int>& b){return a.S<b.S;}


const long double PI  = 3.1415926535;
const long long   mod = 1e9+ 7; 
const int 	  mxN = 1000;
const long long   inf = 1e18;


int n, m;
ll a[1000], b[1000], c[1000], dist[100][100];


int main(){
	cin >>n >> m;
	for(int i=0;i<m;i++){
		cin >> a[i]>>b[i]>>c[i];
	        a[i]--, b[i]--;
	}

	for(int i=0;i<n;i++){
		for(int j=0;j<n;j++){
			if(i == j)dist[i][j] = 0;
			else dist[i][j] = inf;
		}
	}
	for(int i=0;i<m;i++){
		dist[a[i]][b[i]] = min(dist[a[i]][b[i]], c[i]);
		dist[b[i]][a[i]] = min(dist[b[i]][a[i]], c[i]);
	}
	for(int k =0;k<n;k++){
		for(int i=0;i<n;i++){
			for(int j=0;j<n;j++){
				dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j]);
			}
		}
	}

	int ans = m;
	for(int i=0;i<m;i++){
            bool shortest = false;
	    for(int j =0;j<n;j++){
		    if(dist[j][a[i]] + c[i] == dist[j][b[i]])shortest = true;
	    }
	    if(shortest)ans--;
	}


	cout<<ans<<"\n";




}





