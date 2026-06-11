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

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n=nxt();
    if(n==1)
    {
        cout<<"1\n";
        return 0;
    }
    vector <int> primes;
    SieveOfEratosthenes(sqrt(n),primes);
    int p=primes.size();
    map <int,int> m;
    for(int i=1;i<=n;i++)
    {
        int x=i;
        for(int j=0;j<p&&primes[j]*primes[j]<=x;j++)
        {
            while(x%primes[j]==0)
            {
                x/=primes[j];
                m[primes[j]]+=1;
            }
        }
        if(x>1)
            m[x]+=1;
    }
    ll mod=1e9+7;
    ll test=1;
    for(auto it=m.begin();it!=m.end();it++)
        (test*=(it->second+1))%=mod;
    cout<<test<<endl;
    
    return 0;   
}




 
 
