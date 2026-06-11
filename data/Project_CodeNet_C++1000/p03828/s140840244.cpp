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
const long long   INF = 1e9;

int n;
vector <int> primes;

bool isPrime(int num){
	if(num == 1)return false;
	for(int i=2; i*i <= n ;i++){
		if(num%i == 0)return false;
	}
	return true;
}

void genPrime(){
     
     for(int i=2;i<=1000;i++){
            if(isPrime(i))primes.pb(i) ;
     }
}    
 

void solve(){
    cin >> n;
    int freq[1001];
    memset(freq,0,sizeof(freq));
    for(int i = 2;i <= n;i++){
	    int j = 0;
            int num = i;
	    while(j < primes.size()){
		     int cnt = 0;
                     while(num%primes[j] == 0){
			     num/=primes[j];
			     cnt++;
		     }
                     freq[primes[j]] += cnt;
		     j++;
	    }
	    if(num != 1)freq[i]++;
    }
    ll ans = 1;
    for(int i=2;i<=n;i++){
	    if(freq[i])ans = (ans*(freq[i] + 1))%mod;
    }
    cout<<ans<<"\n";
}


int main(){
	genPrime();
	solve();
	return 0;
}
