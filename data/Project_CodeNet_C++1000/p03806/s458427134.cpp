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

    int n=nxt(),ma=nxt(),mb=nxt();
    vector <vector <int> > v;
    vector <int> row(3);
    v.resize(n,row);
    int suma=0,sumb=0;
    for(int i=0;i<n;i++)
    {
        int a=nxt(),b=nxt(),c=nxt();
        v[i][0]=a;v[i][1]=b;v[i][2]=c;
        suma+=v[i][0];
        sumb+=v[i][1];
    }
    int test=INT_MAX;
    for(int mul=1;mul<=400;mul++)
    {
        int A=mul*ma;
        int B=mul*mb;
        if(A>suma||B>sumb)
            break;

        vector <vector <vector <int> > > dp;
        vector <int> r2;
        r2.resize(B+1,-1);
        vector <vector <int> > r1;
        r1.resize(A+1,r2);
        dp.resize(n,r1);
        if(v[0][0]<=A&&v[0][1]<=B)
            dp[0][v[0][0]][v[0][1]]=v[0][2];
        for(int i=1;i<n;i++)
        {
            dp[i]=dp[i-1];
            if(v[i][0]>A||v[i][1]>B)
                continue;

            for(int j=A;j>=0;j--){
                if(j-v[i][0]<0)
                        break;
                for(int k=B;k>=0;k--)
                {
                    if(j-v[i][0]<0||k-v[i][1]<0)
                        break;
                    if(dp[i][j-v[i][0]][k-v[i][1]]!=-1)
                    {
                        if(dp[i][j][k]==-1)
                            dp[i][j][k]=dp[i][j-v[i][0]][k-v[i][1]]+v[i][2];
                        else
                            dp[i][j][k]=min(dp[i][j][k],dp[i][j-v[i][0]][k-v[i][1]]+v[i][2]);
                    }
                }
            }

            if(dp[i][v[i][0]][v[i][1]]==-1)
                dp[i][v[i][0]][v[i][1]]=v[i][2];
            else
                dp[i][v[i][0]][v[i][1]]=min(dp[i][v[i][0]][v[i][1]],v[i][2]);
           


        }
        if(dp[n-1][A][B]!=-1)
            test=min(test,dp[n-1][A][B]);

    }

    if(test==INT_MAX)
        cout<<"-1\n";
    else
        cout<<test<<endl;

    
    
    
    return 0;   
}




 
 
