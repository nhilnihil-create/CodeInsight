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
    int  n=nxt(),k=nxt();
    vector <int> v(n+1);
    ll sum=0;
    for(int i=1;i<=n;i++){
        cin>>v[i];
        sum+=v[i];
    }
    v[0]=INT_MIN;
    sort(all(v));
    if(sum<k)
    {
        cout<<n<<endl;
        return 0;
    }
    int index=0;
    int l=1,r=n;
    while(l<=r)
    {
        int mid=(l+r)/2;
        vector <vector <bool> > dp;
        vector <bool> row;
        row.resize(k,0);
        dp.resize(n+1,row);
        dp[0][0]=1;
        for(int i=1;i<=n;i++)
        {
            dp[i]=dp[i-1];
            if(i==mid)
                continue;
            for(int j=k-1;j>=0;j--)
            {
                if(j-v[i]<0)
                    break;
                if(dp[i][j-v[i]]==1)
                    dp[i][j]=1;
            }
        }
        int left=k-v[mid];
        int right=k-1;
        bool f=0;
        for(int i=0;i<k;i++)
            if(i>=left&&i<=right&&dp[n][i])
            {
                f=1;
                break;
            }
        //cout<<mid<<" "<<f<<endl;
        if(!f)
        {
            index=mid;
            l=mid+1;
        }
        else
            r=mid-1;
    }
    cout<<index<<endl;


    
    
    
    return 0;   
}




 
 
