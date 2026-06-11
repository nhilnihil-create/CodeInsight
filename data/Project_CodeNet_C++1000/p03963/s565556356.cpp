 #include<bits/stdc++.h>
    using namespace std;
    #define ll long long
    #define io ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    int main()
    {
        ll n{},k{};
        cin>>n>>k;
        ll x = (ll)pow((k-1),(n-1));
        cout<<x*k<<endl;
        return 0;
    }