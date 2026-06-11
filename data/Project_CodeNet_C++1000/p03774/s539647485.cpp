#include <iostream>
#include <vector>
#include <cmath>
using namespace std;
using ll = long long;
int main(){
    int n, m;
    cin >> n >> m;
    vector<pair<ll,ll>>s(n),p(m);
    for(int i=0; i<n; i++){
        ll a,b;
        cin >> a >> b;
        s[i] = make_pair(a,b);
    } 
    for(int i=0; i<m; i++){
        ll c, d;
        cin >> c >> d;
        p[i] = make_pair(c,d);
    } 
    for(int i=0; i<n; i++){
        ll d=1e18;
        int point=0;
        for(int j=0; j<m; j++){
            if(d > abs(s[i].first-p[j].first) + abs(s[i].second-p[j].second)){
                d = abs(s[i].first-p[j].first) + abs(s[i].second-p[j].second);
                point = j+1;
            }
        }
        cout << point << endl;
    }
    return 0;
}
