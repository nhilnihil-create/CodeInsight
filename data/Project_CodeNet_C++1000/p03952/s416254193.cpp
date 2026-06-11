#include<bits/stdc++.h> 
using namespace std;
using ll=long long;
typedef pair<ll,ll> P;
#define fi first
#define se second
#define all(v) (v).begin(),v.end()
const ll inf=(1e18);
const ll mod=1000000007;
const ll mod2=998244353;
ll gcd(ll a,ll b) {return b ? gcd(b,a%b):a;}
ll lcm(ll c,ll d){return c/gcd(c,d)*d;}
//ios_base::sync_with_stdio(false);
//cin.tie(NULL);
map<int,ll> mp;
int main(){
ios_base::sync_with_stdio(false);
cin.tie(NULL);
int n,x;
cin>>n>>x;
if(x==1||(x>2*n-2)){
    cout<<"No"<<endl;
    return 0;
}
cout<<"Yes"<<endl;
if(x==2&&n==2){
    cout<<1<<" "<<2<<" "<<3<<endl;
    return 0;
}
vector<bool> used(2*n,false);
vector<int> a(2*n-1,0);
int mid=(2*n-1)/2;
if(x!=2){
    x--;
for(int i=mid-1;i<mid+3;i++){
    if(i==mid+2){
        a[i]=x-4;
    used[x-4]=true;
        break;
    }
    a[i]=x;
    used[x]=true;
    x++;
}
}
else{
    a[mid-1]=x+1;
    a[mid]=x;
    a[mid+1]=x-1;
    a[mid+2]=x+2;
    used[x+1]=true;
    used[x]=true;
    used[x-1]=true;
    used[x+2]=true;
}
int j=1;
for(int i=0;i<2*n-1;i++){
    if(a[i]!=0)continue;
    while(used[j])j++;
    a[i]=j;
    j++;
}
for(int i=0;i<2*n-1;i++)cout<<a[i]<<" ";
cout<<endl;
}