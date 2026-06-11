#include<bits/stdc++.h>
using namespace std;
typedef long long int lli;
typedef unsigned long long int ulli;
#define vec(s) vector<s>;
#define vvec(s) vector<vector<s>> ;
typedef vector<lli> vi;
typedef vector<vi> vvi;
typedef pair<lli,lli> pii;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define YN(x) cout<<(bool x?"Yes":"No")<<endl;
#define out(s) cout<<s<<endl;
#define pb(s) push_back(s);
#define sp " ";
#define INF 10000000000
#define all(s) s.begin(),s.end()
void vout(vector<int> v){
    for(int i=0;i<v.size();i++)
    cout<<v.at(i)<<endl;
}
map<long long int,long long int> prime;
void prime_fact(long long int n){
    long long int nc=n;
    long long int i=2;
    while(nc!=1){
        if(i*i>nc) {
            if(prime.count(nc)) {prime.at(nc)+=1; break;}
            else {prime[nc]=1;}
            break;
        }
        if(nc%i==0){
            long long int count=0;
            while(nc%i==0){
                nc/=i;
                count++;
            }
            if(prime.count(i)) prime.at(i)+=count; 
            else{prime[i]=count;}
        }
        i++;
    }
};
lli gcd(long long int x,long long int y){
    if(y==0) return x;
    return gcd(y,x%y);

}

int main(){
    lli ans=1;
    int n;
    cin>>n;
    rep(i,n){
        lli ti;
        cin>>ti;
        lli g=gcd(ti,ans);
        ti/=g;
        ans*=ti;
    }
    out(ans);
}