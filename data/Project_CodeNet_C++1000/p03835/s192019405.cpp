#include <bits/stdc++.h>
using namespace std;
/************************Contest Template**************************/
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int,int> pii;
typedef pair<long long,long long> pll;
#define FASTIO ios_base::sync_with_stdio(false);cin.tie(0);
struct S{
    int a,b; S(){}S(int _a,int _b)
    { a=_a; b=_b; }
    const bool operator<(const S &o) const{
        return a<o.a;}
};
string exm;
inline void exf(void){ cout<<exm<<"\n"; exit(0); }
template <typename T>
inline void showAll(vector<T> &v,string sep=""){
    for(T &here:v) cout<<here<<sep;}
template <typename T>
inline void showAll(T a[],int st,int end,string sep=""){
    for(int i=st ; i<=end ; i++) cout<<a[i]<<sep; }
template <typename T>
inline void showAll(T a[],int x,int y,int z,int w,string p,string q){
    for(int i=x ; i<=y ; i++){for(int j=z ; j<=w ; j++)
        {cout<<a[i][j]<<p;}cout<<q;}}   
template <typename T>
inline vector<int> int_seperation(T N,int d=10){
    vector<int> v; while(N){v.push_back(N%d); N/=d;}
    reverse(v.begin(),v.end()); return v; }
/************************Contest Template**************************/
//const int SIZE=

int main(){
    int n,s;    scanf("%d %d",&n,&s);
    
    ll ans = 0;
    for(int i=0 ; i<=n ; i++){
        for(int j=i ; j<=n ; j++){
            if(i+j+n<s) continue;
            int k = s-i-j;
            if(k<j) continue;
            if(i==j && j==k) ans++;
            else if(i==j || j==k || i==k) ans+=3;
            else ans+=6;
        }
    }
        
    printf("%lld\n",ans);

    return 0;
}
/*

*/




