		#include<bits/stdc++.h>
		using namespace std;
		#define ll long long
		#define endl "\n"
		ll mod=1e9+7;
		void solve();
		ll exp(ll base,ll power,ll mod){
			power=power%mod;
			ll ans=1;
			while(power){
				if(power & 1){
					ans=(ans*base)%mod;
					power=power-1;
				}
				else{
					base=(base*base)%mod;
					power=power/2;
				}
			}
			return ans%mod;
		}
		int main()
		{	
			ios_base::sync_with_stdio(false);
			cin.tie(NULL);

		/*#ifndef ONLINE_JUDGE
			freopen("input.txt","r",stdin);
			freopen("output.txt","w",stdout);
		#endif*/
		
			int t=1;
			//cin>>t;
			while(t--){
			solve();
			cout << endl;
			}

			cerr << "time taken : "	<< (float)clock() / CLOCKS_PER_SEC << " secs" << endl; 
			return 0;		
		}
		void solve(){
			map<ll,ll>m;
			ll n,num,cnt=0;
			cin>>n;
			for (int i = 0; i < n; ++i)
			{
				cin>>num;
				m[num]++;
			}
			if(m[0]>1){
				cout<<0<<endl;
				return;
			}
			else{
				for(auto x: m){
					if(x.second==2){
						cnt++;
					}
					else if(x.second>2){
						cout<<0<<endl;
						return;
					}
				}
			}
			cout<<exp(2,cnt,mod)%mod;

		}
	