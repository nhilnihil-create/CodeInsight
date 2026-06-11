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
			string s;
			cin>>s;
			for (int i = 0; i < s.size(); ++i)
			{
				if(s[i]==','){
					s[i]=' ';
				}
			}
			cout<<s;
		}
	