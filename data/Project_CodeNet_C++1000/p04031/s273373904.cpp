#include<bits/stdc++.h> 
#define ll long long 
#define pb push_back
#define vec vector<int>
#define fo(i,n) for (int i = 0; i < n; i++)
#define so(v) sort(v.begin(), v.end())
#define fi first
#define se second
using namespace std;  




int main()
{
  int n;
  cin>>n;
 
    vector<int> a(n) ;
    int sum = 0 ;
    fo(i,n){
        cin >> a[i] ;
        sum+=a[i] ;
    }
    sort(a.begin(),a.end()) ;
    int mean = sum/n ;
    int ans = 0 ;
    int ans2 = 0 ;
    fo(i,n){
        ans+=(a[i]-mean)*(a[i]-mean) ;
    }
 
    fo(i,n){
        ans2+=(a[i]-(mean+1))*(a[i]-(mean+1)) ;
    }
 
    cout << min(ans,ans2) << endl ;
 
    return 0 ;


 
    
}



   