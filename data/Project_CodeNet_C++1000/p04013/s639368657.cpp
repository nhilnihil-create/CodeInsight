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
    ll n=nxt(),a=nxt();
    vector <ll> v(n);
    generate(all(v),nxt);
    vector <vector < vector <ll> > > dp;
    vector <ll> row;
    row.resize(2501,0);
    vector <vector  <ll> > row2;
    row2.resize(n+1,row);
    dp.resize(n,row2);

    dp[0][1][v[0]]=1;
    for(ll i=1;i<n;i++)
    {
        dp[i]=dp[i-1];
        dp[i][1][v[i]]+=1;
        for(ll len=1;len<=i;len++)
        {
            for(ll val=1;val<=2500;val++)
                if(dp[i-1][len][val]>0)
                    dp[i][len+1][val+v[i]]+=dp[i-1][len][val];
        }
    }

    ll test=0;
    for(int len=1;len<=n;len++)
        test+=dp[n-1][len][len*a];
    cout<<test<<endl;


    

    
    return 0;   
}


 
 
