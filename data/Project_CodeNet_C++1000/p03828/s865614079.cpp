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


ll n;
vector <int> primes;
bool seive[1001];


void genPrime(){
     memset(seive,1,sizeof(seive));
     int i = 2;
     while(i*i <= 1000){
	     int k = i*i;
	     while(k <= 1000)
	     {
	       	     seive[k] = false;
		     k += i;
	     }
	     i++;
     }
     for(int i= 2;i<=1000;i++){
	     if(seive[i])primes.pb(i);
     }
}


void solve(){
	cin >> n;
        int fac[1001];
	memset(fac,0,sizeof(fac));

        for(int i=2;i<=n;i++){
		int j=0;
		int num = i;
		while(j < primes.size() && num!=1){
                        int cnt =0;
			while(num%primes[j] == 0){
				cnt++;
				num/=primes[j];
			}
			fac[primes[j]]+=cnt;
		        j++;
		}
		if(num != 1)fac[i]++;
	}
	

        ll ans = 1;
        for(int i = 2 ;i <= n; i++){
	       	(ans*=(fac[i]+1))%=mod;
	}
	cout<<ans<<"\n";
}



int main(){
	genPrime();
	solve();
	return 0;
}
