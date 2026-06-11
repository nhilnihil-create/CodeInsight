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
    int n=nxt(),m=nxt();
    vector <vector <int> > edges;
    vector <int> row(3);
    edges.resize(m,row);
    vector <vector <int> > dist;
    vector <int> r2;
    r2.resize(n+1,1e8);
    dist.resize(n+1,r2);
    for(int i=1;i<=n;i++)
        dist[i][i]=0;
    for(int i=0;i<m;i++)
    {
        int u=nxt(),v=nxt(),c=nxt();
        edges[i][0]=u;
        edges[i][1]=v;
        edges[i][2]=c;
        dist[u][v]=c;
        dist[v][u]=c;
    }

    for(int i=1;i<=n;i++)
        for(int j=1;j<=n;j++)
            for(int k=1;k<=n;k++)
                if(dist[j][k]>dist[j][i]+dist[i][k])
                    dist[j][k]=dist[j][i]+dist[i][k];
    int test=0;
    for(int i=0;i<m;i++)
    {
        if(edges[i][2]>dist[edges[i][0]][edges[i][1]])
            test++;
    }
    cout<<test<<endl;

    
    return 0;   
}




 
 
