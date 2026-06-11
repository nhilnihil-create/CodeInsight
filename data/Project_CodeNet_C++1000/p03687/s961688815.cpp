#include <bits/stdc++.h>
#define rep(i,a,b) for(int i=int(a);i<int(b);++i)
#define SIZE 200005
#define INF 1000000005LL
#define MOD 1000000007
using namespace std;
typedef long long int ll;
typedef pair <int,int> P;
struct position{
    int now = -1;
    int maximum = -1;
};
int main(){
    string s;
    cin >> s;
    map<char,position> data;
    rep(i,0,s.size()){
        int now_dis = i - data[s[i]].now -1;
        data[s[i]].maximum = max(now_dis,data[s[i]].maximum);
        data[s[i]].now = i;
    }
    int ans = 1000000;
    for(auto x: data){
        int a = s.size()-data[x.first].now -1;
        data[x.first].maximum = max(data[x.first].maximum,a);
        ans = min(ans,data[x.first].maximum);
    }
    cout<<ans<<endl;
    
    


    return 0;
}