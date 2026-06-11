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
    ll n=nxtl(),w=nxtl();
    vector <vector <ll> > v;
    vector <ll> row;
    v.resize(4,row);
    ll base;
    for(int i=0;i<n;i++)
    {
        ll x=nxtl(),y=nxtl();
        if(i==0)
            base=x;
        v[x-base].push_back(y);
    }
    for(int i=0;i<4;i++)
        sort(all(v[i]),greater<int>());
    ll test=0;
    ll a=0;
    for(int i=0;i<=v[0].size();i++){
        if(i>0)
            a+=v[0][i-1];
        ll b=0;
        for(int j=0;j<=v[1].size();j++)
        {
            if(j>0)
                b+=v[1][j-1];
            ll c=0;
            for(int k=0;k<=v[2].size();k++)
            {
                if(k>0)
                    c+=v[2][k-1];
                ll d=0;
                for(int l=0;l<=v[3].size();l++)
                {
                    if(l>0)
                        d+=v[3][l-1];
                    //cout<<a<<" "<<b<<" "<<c<<" "<<d<<endl;
                    if(base*i+(base+1)*j+(base+2)*k+(base+3)*l<=w&&test<a+b+c+d)
                        test=a+b+c+d;

                }
            }
        }
    }

    cout<<test<<endl;
    
    
    return 0;   
}




 
 
