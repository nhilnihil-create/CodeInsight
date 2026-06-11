#include <bits/stdc++.h>
#define rep(i,a,b) for(int i=int(a);i<int(b);++i)
#define SIZE 200005
#define INF 1000000005LL
#define MOD 1000000007
using namespace std;
typedef long long int ll;
typedef pair <int,int> P;
int main(){
    int a,b,c;
    cin >> a >> b >> c;
    rep(i,0,b){
        if((a*i)%b==c){
            cout<<"YES"<<endl;
            return 0;
        }
    }
    cout<<"NO"<<endl;
  return 0;
}