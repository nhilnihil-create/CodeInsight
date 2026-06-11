  	#include <bits/stdc++.h>
  	using namespace std;
  	typedef long long int ll;
    int main() {
  		// #ifndef ONLINE_JUDGE
  		// 	// for getting input from input.txt
  		// 	freopen("input.txt", "r", stdin);
  		// 	// for writing output to output.txt
  		// 	freopen("output.txt", "w", stdout);
  		// #endif
      ios_base::sync_with_stdio(false);
      cin.tie(NULL);
      ll n,k=0,l=0,b=0;
      cin>>n;
      vector<ll> v(n+1,0);
      for (ll i = 0; i < n; ++i)
        {
          cin>>v[i];            
        }  
      sort(v.begin(), v.end());
      

      for (int i = 0; i < n; i +=2)
      {
        if(v.at(i) == v.at(i+1)){
          l = b;
          b = v[i];
        }
        else{
          i--;
        }
      }
      cout<<l*b<<"\n";
}
