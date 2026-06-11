		#include<bits/stdc++.h>
		using namespace std;
		#define ll long long
		#define endl "\n"
		void solve();
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
			int k,s,ans=0;
			cin>>k>>s;
			for(int x=0;x<=k;x++){
				for(int y=0;y<=k;y++){
					int z=s-x-y;
					if(z>=0 && z<=k){
						ans++;
					}	
				}
			}
			cout<<ans;
		}
	