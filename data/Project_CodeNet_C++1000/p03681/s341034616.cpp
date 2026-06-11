#include<bits/stdc++.h>
using namespace std;
#define int long long int
#define pb push_back
#define mp make_pair
#define all(x) x.begin(), x.end()
#define tr(it, a) for(auto it = a.begin(); it != a.end(); it++)
typedef vector<int>         vi;
const int mod = 1000000007;


int factorial(int n ){
    int ans = 1;
    for(int i =1;i <=n;i++){
        ans = ((ans%mod)*(i%mod))%mod;
    }
    return ans;
}




int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int d,c;
    cin>>d>>c;
    if(abs(d-c)>1){
        cout<<0<<endl;
        return 0;
    }
    else{
        int s = min(d,c);
        int b = max(d,c);
        if(s==b){
            int x =factorial(s);
            cout<<((x*x*2)%mod);
        }
        else{
            int x = factorial(s);
            cout<< (x*(((b%mod)*x)%mod))%mod;
        }



    }






}











































