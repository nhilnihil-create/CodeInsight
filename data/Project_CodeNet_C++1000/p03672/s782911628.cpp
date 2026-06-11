#include <bits/stdc++.h>
#define rep(i,a,b) for(int i=int(a);i<int(b);++i)
#define SIZE 200005
#define INF 1000000005LL
#define MOD 1000000007
using namespace std;
typedef long long int ll;
typedef pair <int,int> P;
int main(){
    string s;
    cin >> s;
    int halfsize = s.size()/2;
    for(int i=halfsize-1;i>0;i--){
        string t = s.substr(0,i);
        string t_2 = s.substr(0,i*2);
        if(t+t==t_2){
            cout<<i*2<<endl;
            return 0;
        }
    }
    cout<<-1<<endl;
  return 0;
}