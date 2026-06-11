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

map<string,string> inp;

int main() {
    //freopen("output.txt","w",stdout);
    //freopen("input.txt","r",stdin);
    int m,n,i;
    in(n),in(m);
    string ss[n];
    for(i=0;i<n; i++) {
        cin>>ss[i];
    }
    sort(ss,ss+n);
    for(i=0;i<n;i++) {
        cout << ss[i];
    }
    cout << endl;
    done;
}