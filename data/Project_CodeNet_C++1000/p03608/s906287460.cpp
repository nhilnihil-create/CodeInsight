#include<bits/stdc++.h>
#include<string.h>
 
typedef long long int ll;
#define all(x) (x).begin(), (x).end()
 
using namespace std;

int nxt() {
    int x;
    cin >> x;
    return x;
}

ll nxtl(){
    ll x;
    cin>>x;
    return x;
}
 
void SieveOfEratosthenes(int n,vector <int> &primes) 
{ 
    // Create a boolean array "prime[0..n]" and initialize 
    // all entries it as true. A value in prime[i] will 
    // finally be false if i is Not a prime, else true. 
    bool prime[n+1]; 
    memset(prime, true, sizeof(prime)); 
  
    for (int p=2; p*p<=n; p++) 
    { 
        // If prime[p] is not changed, then it is a prime 
        if (prime[p] == true) 
        { 
            // Update all multiples of p greater than or  
            // equal to the square of it 
            // numbers which are multiple of p and are 
            // less than p^2 are already been marked.  
            for (int i=p*p; i<=n; i += p) 
                prime[i] = false; 
        } 
    } 
  
    // Print all prime numbers 
    for (int p=2; p<=n; p++) 
       if (prime[p]) 
          primes.push_back(p);
} 
 
ll max(ll a,ll b)
{
    if(a>b)
        return a;
    return b;
}
 
ll power(ll x, ll y,ll mod) 
{ 
    ll temp; 
    if( y == 0) 
        return 1; 
    temp = power(x, y/2,mod); 
    if (y%2 == 0) 
        return (temp*temp)%mod; 
    else
        return (((x*temp)%mod)*temp)%mod; 
}

ll binomialCoeff(ll n, ll k) 
{ 
    ll C[k+1]; 
    memset(C, 0, sizeof(C)); 
  
    C[0] = 1;  // nC0 is 1 
  
    for (ll i = 1; i <= n; i++) 
    { 
        // Compute next row of pascal triangle using 
        // the previous row 
        for (ll j = min(i, k); j > 0; j--) 
            C[j] = C[j] + C[j-1]; 
    } 
    return C[k]; 
} 

int n,m,r;
vector <int> towns;
vector <vector <int> > dist;
vector <vector <int> > g;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    n=nxt();m=nxt();r=nxt();
    towns.resize(r);
    generate(all(towns),nxt);
    vector <int> r1;
    r1.resize(n+1,1e9);
    dist.resize(n+1,r1);
    for(int i=1;i<=n;i++)
        dist[i][i]=0;
    for(int i=0;i<m;i++)
    {
        int u=nxt(),v=nxt(),c=nxt();
        dist[u][v]=dist[v][u]=c;
    }
    for (int k = 1; k <=n; k++)  
    {  
        // Pick all vertices as source one by one  
        for (int i = 1; i <=n; i++)  
        {  
            // Pick all vertices as destination for the  
            // above picked source  
            for (int j = 1; j <=n; j++)  
            {  
                // If vertex k is on the shortest path from  
                // i to j, then update the value of dist[i][j]  
                if (dist[i][k] + dist[k][j] < dist[i][j])  
                    dist[i][j] = dist[i][k] + dist[k][j];  
            }  
        }  
    }  
    int tot=1;
    for(int i=2;i<=r;i++)
        tot*=i;
    int test=INT_MAX;
    for(int i=0;i<tot;i++)
    {
        int temp=0;
        for(int i=0;i<r-1;i++)
            temp+=dist[towns[i]][towns[i+1]];
        if(temp<test)
            test=temp;
        next_permutation(all(towns));
    }
    cout<<test<<endl;
    
    
    
    return 0;   
}




 
 
