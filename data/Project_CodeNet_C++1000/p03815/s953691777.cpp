#include<bits/stdc++.h>
using namespace std;
#define int long long int
#define pb push_back
#define mp make_pair
#define all(x) x.begin(), x.end()
#define tr(it, a) for(auto it = a.begin(); it != a.end(); it++)
typedef vector<int>         vi;
const int mod = 1000000007;


int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int x;
    cin>>x;
    int ele = x/11LL;
    int rem = x%11LL;
    if(rem==0){
        cout<<ele*(2LL)<<endl;
    }
    else if(rem<=6){
        cout<<ele*(2LL)+(1LL)<<endl;
    }
    else{
        cout<<ele*(2LL)+(2LL)<<endl;
    }
    }
    
    




















