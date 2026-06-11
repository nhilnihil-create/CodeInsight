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
			int sx,sy,tx,ty;
			cin>>sx>>sy>>tx>>ty;
			const int dx=abs(tx-sx),dy=abs(ty-sy);
			for (int i = 0; i < dx; ++i)
			{
				cout<<'R';
			}
			for (int i = 0; i < dy; ++i)
			{
				cout<<'U';
			}
			for (int i = 0; i < dx; ++i)
			{
				cout<<'L';
			}
			for (int i = 0; i < dy+1; ++i)
			{
				cout<<'D';
			}
			for (int i = 0; i < dx+1; ++i)
			{
				cout<<'R';
			}
			for (int i = 0; i < dy+1; ++i)
			{
				cout<<'U';
			}
			cout<<'L';
			cout<<'U';
			for (int i = 0; i < dx+1; ++i)
			{
				cout<<'L';
			}
			for (int i = 0; i < dy+1; ++i)
			{
				cout<<'D';
			}
			cout<<'R';
		}
	