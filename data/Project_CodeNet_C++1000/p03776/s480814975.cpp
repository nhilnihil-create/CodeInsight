 #include<bits/stdc++.h>
    using namespace std;
    typedef long long int ll;
    typedef unsigned long long int ull;
    const int MOD = (int)1e9+7;
    const int MAX = 1e6;
    ll arr[120];
    ll nCr(ll n, ll r)
    {
        ll C[r+1];
        memset(C, 0, sizeof(C));
        C[0] = 1;
        for (ll i = 1; i <= n; i++)
        {
            for (ll j = min(i, r); j > 0; j--)
                C[j] = (C[j] + C[j-1]);
        }
        return C[r];
    }
    int main()
    {
        ll tot=0;
        long double ans=0,sum=0,cnt=0;
        map<ll,int>N,R;
        int n,a,b;
        cin>>n>>a>>b;
        for(int i=0; i<n; i++){
        	cin>>arr[i];
			N[arr[i]]++;
		}
        sort(arr,arr+n);
        ll last ;
        for(int i=n-1; i>=0; i--)
        {
            sum+=arr[i];
            R[arr[i]]++;
            cnt++;
            if(cnt>b)
                break;
            if(cnt==a)
            {
                last = arr[n-1];
                ans=sum/cnt;
            }
            if(cnt>=a)
            {
                long double cur=(sum/cnt);
                if(cnt==a)
                    {tot+=nCr(N[arr[i]],R[arr[i]]);
                    }
                else if(arr[i]==last)
                {
                 tot+=nCr(N[arr[i]],R[arr[i]]);
                }
            }
        }
        cout<<setprecision(18)<<fixed<<ans<<endl;
        cout<<tot<<endl;
        return 0;
    }
