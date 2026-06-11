#include <bits/stdc++.h>
using namespace std;
#define fast()  ios_base::sync_with_stdio(false); cin.tie(NULL);
#define endl "\n"
#define mod 1000000007
#define PI 3.14159265358979323846
#define f first
#define s second
#define un unordered
#define for0(i,n) for(i=0;i<n;i++)
#define for1(j,n) for(j=1;j<=n;j++)
#define ll long long int
vector<ll> primes;
bool specialPrimeNumbers(ll n, ll k) 
{ 

	for (ll i = 0; i < primes.size(); i++) {
		for (ll j = 0; j < i; j++) { 
			
			if (primes[i] + primes[j]== n) { 
				return true;
			} 
		} 
	} 
	return false; 
} 

bool cmp(pair<int,int>  p,pair<int,int> p1){
	return p.first<p1.first;
}

class edge{
	public :
	int a,b;
};
struct subset 
{ 
	int parent; 
	int rank; 
}; 

int find(struct subset subsets[], int i) 
{ 
    // find root and make root as parent of i (path compression) 
	if (subsets[i].parent != i) 
		subsets[i].parent = find(subsets, subsets[i].parent); 

	return subsets[i].parent; 
} 

void Union(struct subset subsets[], int x, int y) 
{ 
	int xroot = find(subsets, x); 
	int yroot = find(subsets, y); 

	if (subsets[xroot].rank < subsets[yroot].rank) 
		subsets[xroot].parent = yroot; 
	else if (subsets[xroot].rank > subsets[yroot].rank) 
		subsets[yroot].parent = xroot; 

	else
	{ 
		subsets[yroot].parent = xroot; 
		subsets[xroot].rank++; 
	} 
} 
void dfs(vector<int> edges[],int a,int b,int visit[],map<int,vector<int>> &mp){
	visit[a]=1;
	for(auto i : edges[a]){
		
		if(visit[i]==1){
			continue;
		}
		else{
			mp[b].push_back(i);

			dfs(edges,i,b+1,visit,mp);
		}
	}
}
string result(string s){
	
	return s;
}
void simpleSieve(int limit) 
{ 
	bool mark[limit+1]; 
	memset(mark, true, sizeof(mark)); 

	for (int p=2; p*p<limit; p++) 
	{ 
        // If p is not changed, then it is a prime 
		if (mark[p] == true) 
		{ 
            // Update all multiples of p 
			for (int i=p*2; i<limit; i+=p) 
				mark[i] = false; 
		} 
	} 

	for (int p=2; p<limit; p++) 
	{ 
		if (mark[p] == true) 
		{ 
			primes.push_back(p); 
       //     cout << p << " "; 
		} 
	} 
} 

void segmentedSieve(int n) 
{ 
	int limit = floor(sqrt(n))+1; 
	simpleSieve(limit);  

	int low = limit; 
	int high = 2*limit; 

	while (low < n) 
	{ 
		if (high >= n)  
			high = n; 

		bool mark[limit+1]; 
		memset(mark, true, sizeof(mark)); 

		for (int i = 0; i < primes.size(); i++) 
		{ 
			int loLim = floor(low/primes[i]) * primes[i]; 
			if (loLim < low) 
				loLim += primes[i]; 

			for (int j=loLim; j<high; j+=primes[i]) 
				mark[j-low] = false; 
		} 

		for (int i = low; i<high; i++) 
			if (mark[i - low] == true) 
				primes.push_back(i);

			low = low + limit; 
			high = high + limit; 
		} 
	} 
	int dfs(vector<ll> edges[],ll &u,ll v){

		for(auto i:edges[u]){
			if(i!=v){
				u=i;
				return 1;
			}
		}
		return 0;
	}

	int dfs1(vector<ll> edges[],ll &u,ll v,map<int,int> &mp){

		for(auto i:edges[u]){
			if(i==v){
				u=i;
				return 1;
			}
			else{
				if(mp.count(i)>0)
					continue;
				u=i;
				mp.insert({i,1});
			}
		}

		return 0;
	}
	ll pairORSum(ll arr[], int n) 
	{ 
    ll ans = 0; // Initialize result 

    // Consider all pairs (arr[i], arr[j) such that 
    // i < j 
    for (int i = 0; i < n; i++) 
    	for (int j = i + 1; j < n; j++) 
    		ans += arr[i] ^ arr[j]; 

    	return ans%mod; 
    }
    ll power(ll x,ll y, ll p) 
    { 
    ll res = 1;      // Initialize result 

    x = x % p;  // Update x if it is more than or  
                // equal to p 

    while (y > 0) 
    { 
        // If y is odd, multiply x with result 
    	if (y & 1) 
    		res = (res*x) % p; 

        // y must be even now 
        y = y>>1; // y = y/2 
        x = (x*x) % p;   
    } 
    return res; 
} 
long long int sumXOR(ll arr[], ll n) 
{ 
	long long int sum = 0; 
	ll zero[62]={0},one[62]={0};
	ll maxi=0;
	for(int i=0;i<n;i++){
		ll count=0;
		while(count<62){
			if(arr[i]%2==0){
				zero[count]++;
			}
			else{
				one[count]++;
			}
			arr[i]=arr[i]/2;
			maxi=max(count,maxi);
			count++;

		}

	}
	ll ans=0;
	for(int i=0;i<=maxi;i++){
		ans=(ans+((zero[i]*one[i])%mod)*(power(2,i,mod))%mod)%mod;
	}

	return ans;
} 

long double distance(ll x,ll y,ll x1,ll y1){

	return (sqrt(pow(abs(x-x1),2)+pow(abs(y-y1),2)));
}
long double fact(int n){
	if(n==1){
		return 1;
	}
	return n*fact(n-1);
}
void solve1(){
}
bool cmp1(pair<ll,ll> p,pair<ll,ll> p1){
	return (p.second<p1.second);
}
ll set_bit(ll n){
	ll count=0;
	while(n!=0){
		if(n%2==1){
			count++;
		}
		n=n/2;
	}
	return count;
}
ll pow1(ll a,ll b){
	if(b==0)
		return 1;
	return a*pow1(a,b-1);
}
void solve(){


	ll n;
	cin>>n;
	int arr[n];
	vector<pair<int,int>> v;
	for(int i=0;i<n;i++){
		cin>>arr[i];
		v.push_back({arr[i],i});
	}
	sort(v.begin(),v.end(),cmp);
	int count=0,res=0;
	for(auto i:v){
		if(i.second%2==count%2){
			//cout<<res<<endl;
			count++;
			continue;
		}	
		else{
			res++;
		}
		count++;
	}

	//cout<<count<<endl;
	cout<<res/2<<endl;
}
int main(){

	fast()
	int t=1;
	//cin>>t;
	for(int i=0;i<t;i++)
		solve();		
	return 0;
}


	