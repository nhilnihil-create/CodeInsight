#include <bits/stdc++.h>
#define rep(i,a,b) for(int i=int(a);i<int(b);++i)
#define SIZE 200005
#define INF 1000000005LL
#define MOD 1000000007
using namespace std;
typedef long long int ll;
typedef pair <int,int> P;
int main(){
    ll a,b,x;
    cin >> a >> b >> x;
    ll num_a,num_b;
    if(a==0){
        num_b = b/x;
        cout<<num_b+1<<endl;
    }else{
        num_a = (a-1)/x;
        num_b = b/x;
        cout<<num_b-num_a<<endl;
        
    }
    
    return 0;
}
