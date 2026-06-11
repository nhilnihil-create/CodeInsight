        #include <bits/stdc++.h>
        //#define endl '\n'
        #define modulo 1000000007
        #define int long long
        #pragma GCC optimize("-Ofast")
        #define float double
        #define PI 3.141592653589793238462643383279502884
        #define sinDegrees(x) sin((x) * PI / 180.0)
        #define tanDegrees(x) tan((x) * PI / 180.0)
        #define atanDegrees(x) atan(x)* 180.0 / PI
        #define f first
       // #define s second
        using namespace std;
        int power(int x,int y,int m)
        {
        int temp;
        if(y == 0)
        return 1;
        temp = (power(x, y/2,m))%m;
        if (y%2 == 0)
        return ((temp%m)*temp);
        else
        return ((x*temp%m)*temp%m)%m;
        }
        int inv(int x)
        {
        return (power(x,modulo-2,modulo))%modulo;
        }
        bool comp(int a,int b)
        {
            return a>b;
        }
        ///Solution created by:Ahmadsm2005
        int32_t main()
        {
            //freopen("output.txt","w", stdout);
            //freopen("input0.txt","r", stdin);
            iostream::sync_with_stdio(0);
            cin.tie(0);
            cout.tie(0);
            string s;
            cin>>s;
            vector<vector<int>>lolz(26);
            for(int i=0;i<s.size();i++){
            lolz[s[i]-'a'].push_back(i+1);
            }
            int miner=INT_MAX;
            for(int i=0;i<26;i++){
            if(lolz[i].size())
            for(int l=0;l<lolz[i].size()-1;l++){
            miner=min(miner,lolz[i][l+1]-lolz[i][l]);
            if(miner<3){
            cout<<lolz[i][l]<<' '<<lolz[i][l+1];
            exit(0);
            }
            }
            }
            cout<<-1<<' '<<-1;
            return 0;
        }
