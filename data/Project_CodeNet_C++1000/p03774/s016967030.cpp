#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using P = pair<int,int>;
#define INF 1000000007
//0=48,A=65,a=97

int main() {
    int n,m;cin >> n >> m;
    vector<int> a(n);
    vector<int> b(n);for(int i=0;i<n;i++) cin >> a[i] >> b[i];  
    vector<int> c(m);
    vector<int> d(m);for(int i=0;i<m;i++) cin >> c[i] >> d[i];  
    
    for(int i = 0; i < n; i++) {
        int mi=INF,x=-1;
        for(int j = 0; j < m; j++) {
            if(abs(a[i]-c[j])+abs(b[i]-d[j])<mi){
                mi=abs(a[i]-c[j])+abs(b[i]-d[j]);
                x=j+1;
            }
        }
        cout << x << endl;
    }

    return 0;
}