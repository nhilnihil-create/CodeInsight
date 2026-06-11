#include <bits/stdc++.h>
#define int long long
using namespace std;
//string sort (s.begin(),s.end());

main() {
    ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);


       int n,k,x,y;
       cin>>n>>k>>x>>y;
       int sum=0;
       if(k>n)
       {
           cout<<n*x<<endl;

       }
       else
       {
            sum+=(k*x);
       sum+=(n-k)*y;
       cout<<sum<<endl;


       }



}

