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

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    ll n=nxt();
    ll test=-1e16;
    multiset <ll> a,b,c;
    vector <ll> v(3*n);
    generate(all(v),nxtl);
    ll left=0,right=0;
    for(int i=0;i<n;i++)
    {
        left+=v[i];
        a.insert(v[i]);
    }
    for(int i=n;i<3*n;i++)
        c.insert(v[i]);
    for(int i=0;i<n;i++)
    {
        auto it=c.begin();
        b.insert(*it);
        right+=*it;
        c.erase(it);
    }
    test=left-right;
    //cout<<test<<endl;
    for(int i=n;i<2*n;i++)
    {
        ll val=v[i];
        if(val>*a.begin())
        {
            left-=*a.begin();
            left+=val;
            a.erase(a.begin());
            a.insert(val);
        }
        if(c.find(val)!=c.end())
        {
            c.erase(c.find(val));
        }
        else
        {
            b.erase(b.find(val));
            right-=val;
            b.insert(*c.begin());
            right+=*c.begin();
            c.erase(c.begin());
        }
        if(left-right>test)
            test=left-right;
        //cout<<i<<" "<<left<<" "<<right<<" "<<test<<endl; 
    }
    cout<<test<<endl;
    
    
    return 0;   
}




 
 
