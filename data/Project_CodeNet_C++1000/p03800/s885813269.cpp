#include<bits/stdc++.h> 
using namespace std;
using ll=long long;
typedef pair<int,int> P;
#define fi first
#define se second
#define all(v) (v).begin(),(v).end()
const ll inf=(1e18);
const ll mod=1000000007;
//ios_base::sync_with_stdio(false);
//cin.tie(NULL);
ll gcd(ll a,ll b) {return b ? gcd(b,a%b):a;}
template<class T> bool chmax(T &a, const T &b) { if (a<b) { a=b; return 1; } return 0; }
template<class T> bool chmin(T &a, const T &b) { if (a>b) { a=b; return 1; } return 0; }
int main(){
ios_base::sync_with_stdio(false);
cin.tie(NULL);
int n,m;
cin>>n;
string s;
vector<string> tmp={"SS","SW","WS","WW"};
cin>>s;
for(int i=0;i<4;i++){
   vector<char> a(n,'!');
   a[0]=tmp[i][0],a[1]=tmp[i][1];
   bool ok=true;
   for(int j=1;j<=n;j++){
        if(s[j%n]=='o'&&a[j%n]=='S'){
            if(a[(j+1)%n]=='!')a[(j+1)%n]=a[j-1];
            else {
                if(a[(j+1)%n]!=a[j-1])ok=false;
            }
        }
        if(s[j%n]=='x'&&a[j%n]=='W'){
            if(a[(j+1)%n]=='!')a[(j+1)%n]=a[j-1];
            else {
                if(a[(j+1)%n]!=a[j-1])ok=false;
            }
        }
        if(s[j%n]=='x'&&a[j%n]=='S'){
            if(a[(j+1)%n]=='!'){
                if(a[j-1]=='S')a[(j+1)%n]='W';
                else a[(j+1)%n]='S';
            }
            else {
                if(a[(j+1)%n]==a[j-1])ok=false;
            }
        }
        if(s[j%n]=='o'&&a[j%n]=='W'){
            if(a[(j+1)%n]=='!'){
                if(a[j-1]=='S')a[(j+1)%n]='W';
                else a[(j+1)%n]='S';
            }
            else {
                if(a[(j+1)%n]==a[j-1])ok=false;
            }
        }
      }
    if(ok){
        for(int j=0;j<n;j++)cout<<a[j];
        cout<<endl;
        return 0;
    }  
   }
   cout<<-1<<endl;
}