#include <bits/stdc++.h>
#define rep(i,a,b) for(int i=int(a);i<int(b);++i)
#define SIZE 200005
#define INF 1000000005LL
#define MOD 1000000007
using namespace std;
typedef long long int ll;
typedef pair <int,int> P;
vector<int> x = {1,-1,0,0};
vector<int> y = {0,0,-1,1};
int main(){
    ll n,a,b;
    cin >> n >> a >> b;
    if(n==1){
        if(a==b){
            cout<<1<<endl;
            return 0;
        }else{
            cout<<0<<endl;
            return 0;
        }
    }
    if(a>b){
        cout<<0<<endl;
        return 0;
    }
    cout<<b*(n-1)+a-(a*(n-1)+b)+1<<endl;
  return 0;
}