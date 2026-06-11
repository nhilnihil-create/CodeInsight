#include<bits/stdc++.h>

#define forw(m,i,n) for(i=m; i<n; i++)
#define done return 0
#define in(x) cin >> x
#define out(x) cout << x << endl
#define pb(x) push_back(x)
#define w(x) while(x--)
#define maxx 1000000000

using namespace std;

typedef long long ll;

 map<int,int>dig;

int main() {
    //freopen("output.txt","w",stdout);
    //freopen("input.txt","r",stdin);
    int f=0,s=0;
    for(int i=0; i<3; i++) {
        int x;
        in(x);
        if(x==5) f++;
        else s++;
    }
    if(f==2 && s==1) cout << "YES\n";
    else cout << "NO\n";
    done;
}