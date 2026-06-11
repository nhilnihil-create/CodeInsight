#include<bits/stdc++.h>
#define ll long long
#define F(i,a,b) for(ll i=a;i<b;i++)
#define RF(i,a,b) for(ll i=a;i>b;i--)
#define pii pair<ll,ll>
#define ff first
#define ss second
#define pb(x) push_back(x)
#define pob pop_back
#define mp(x,y) make_pair(x,y)
#define mod 1000000007
#define w(t) int t; cin>>t;while(t--)
using namespace std;
const int inf=(int)1e9;
char flip_bits(char c){return (c == '0')? '1': '0';}

bool isPrime(int n) 
{ 
    // Corner case 
    if (n <= 1) 
        return false; 
  
    // Check from 2 to n-1 
    for (int i = 2; i < n; i++) 
        if (n % i == 0) 
            return false; 
  
    return true; 
}
ll numberOfOneBitsInInteger(ll input) {
  ll numOneBits = 0;

  ll currNum = input;
  while (currNum != 0) {
    if ((currNum & 1) == 1) {
      numOneBits++;
    }
    currNum = currNum >> 1;
  }
  return numOneBits;
}

int main()
{
    
    ios::sync_with_stdio(0);   
    cin.tie(0);   
   
  
    
   string A,B,C;
   cin>>A>>B>>C;
   if(A[A.length()-1]==B[0] && B[B.length()-1]==C[0])
   {
    cout<<"YES";
   }
   else
   {
    cout<<"NO";
   }
return 0;
}