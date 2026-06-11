        #include <bits/stdc++.h>
        using namespace std;
        int main(){
			long long n,c,k,t[100005],ans=0;
			cin>>n>>c>>k;
			for(int i=0;i<n;i++){
				cin>>t[i];
			}
			sort(t,t+n);
			int time=0,now=1;
			for(int i=1;i<n;i++){
				if(now==c){
					ans++;
					now=0;
					time=i;
				}
				if(t[time]+k<t[i]){
					ans++;
					now=0;
					time=i;
				}
				now++;
			}
			ans++;
			cout<<ans<<endl;
    		return(0);
        }