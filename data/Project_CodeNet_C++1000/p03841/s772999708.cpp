#include <bits/stdc++.h>
using namespace std;
#define x first
#define y second
#define dbg(x) cout << #x << '=' << x << '\n';
#define ll long long
#define pi pair<int,int>
#define pl pair<long long,long long>
#define lg length()
#define pb push_back
ifstream in("file.in");
ofstream out("file.out");
#define MAXN 100005
#define INF 1000000005
#define LINF 1000000000000000005

long long n,x[505],a[250005],cnt[505],q,j;

pl t;

set <pl> s;
queue <int> v;


int main() {
    cin >> n;
    cin >> x[1]; a[x[1]]=1;
    for(int i=2;i<=n;i++) cin >> x[i],s.insert({x[i]-i,i}),a[x[i]]=i;
    q=n*n; j=1;
    for(int i=1;i<=q;i++){
        if(a[i]){
            if(cnt[a[i]]!=a[i]-1){
                cout << "No";
                return 0;
            }
            if(a[i]!=n) v.push(a[i]);
            continue;
        }
        if(s.size()){
            t=*s.begin();
            s.erase(s.begin());
            a[i]=t.y;
            cnt[t.y]++;
            if(cnt[t.y]!=t.y-1){
                t.x++;
                s.insert(t);
            }
        }
        else if(v.size()){
            a[i]=v.front();
            cnt[v.front()]++;
            while(v.size() && cnt[v.front()]==n-1) v.pop();
        }
        else{
            cout << "No";
            return 0;
        }
        //cout << a[i] << ' ';
    }
    cout << "Yes\n";
    for(int i=1;i<=q;i++) cout << a[i] << ' ';
}
