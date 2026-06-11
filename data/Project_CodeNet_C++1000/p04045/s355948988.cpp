    #include <bits/stdc++.h>
    using namespace std;
    #define ll long long

    int d[10]{};

    int main()
    {
        ll n{},k{};
        cin>>n>>k;
        for(ll i=0;i<k;i++){
            int t{};
            cin>>t;
            d[t] = 1;
        }
        for(ll i=n;i<1000005;i++){
            string s = to_string(i);
            for(ll j=0;j<s.size();j++){
                if(d[ s[j] - '0']){
                    goto j;
                }
            }
            cout<<i;
            break;
            j:;
        }

        return 0;
    }