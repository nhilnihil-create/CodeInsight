#include <bits/stdc++.h>

typedef long long ll;
using namespace std;
const int INF = 1e9;
long long mod = 1000000000+7;
vector<vector<int> >g;
   //         int n,m;

    vector<vector<int> > grid(501,vector<int>(501,INF));
    vector<vector<int> > x(501,vector<int>(501,-1));
  long long  pow(long long  a, long long  b, long long m)
 {
        stack<int>k;
        int j = 128;
        int l = 1;
       int an = 1;
        while(b){
            if(b>=j){
                k.push(j);
                b-=j;
            }
            j/=2;
        }
        while(!k.empty()){
            if(k.top()==l){
                an = (an*a)%mod;
                k.pop();
            }
            a = (a*a)%mod;
            l*=2;
        }

        return an;
 }


 int main(){
   ios_base::sync_with_stdio(0);cin.tie(NULL);
   // freopen("zeros.in","r",stdin);
    //freopen("pizza.out","w",stdout);
			long long n,x;
   cin>>n>>x;
   			cout<< 3*(n-__gcd(n,x))<<endl;
                return 0;
}
