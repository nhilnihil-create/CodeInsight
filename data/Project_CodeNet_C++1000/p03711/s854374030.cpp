#include <bits/stdc++.h>
#include <string.h>
using namespace std;
#define rep(i, n) for(int i = 0; i < (int)(n); i++)
#define FOR(i, m, n) for(int i = m; i < n; i++) 
#define mod 1000000007
#define pi 3.1415926535
typedef long long ll;

int main(){
    int x,y;
    cin>>x>>y;
    set<int>a={1,3,5,7,8,10,12};
    set<int>b={4,6,9,11};
    set<int>c={2};
    if((a.count(x)&&a.count(y))||(b.count(x)&&b.count(y))||(c.count(x)&&c.count(y))){
        cout<<"Yes"<<endl;
    }else{
        cout<<"No"<<endl;
    }
    return 0;
}