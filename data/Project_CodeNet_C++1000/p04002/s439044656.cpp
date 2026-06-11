#include <bits/stdc++.h>
using namespace std;

using P = pair<int,int>;

int main() {
    int H, W, n;
    cin >> H >> W >> n;
    vector<P> v, at;
    for (int i=0; i<n; i++) {
        int a,b;
        cin >> a >> b;
        --a; --b;
        v.push_back(make_pair(a,b));
        for(int i=0; i<3; i++) {
            for(int j=0; j<3; j++) {
                if ( a-i>=0 && b-j>=0 && a-i<H-2 && b-j<W-2 )
                    at.push_back(make_pair(a-i,b-j));
            }
        }
    }
    sort(v.begin(), v.end());
    sort(at.begin(), at.end());
    at.resize(unique(at.begin(), at.end())-at.begin());
    
    vector<long long> ans(10);
    ans[0]=(long long)(H-2)*(W-2)-(long long) at.size();
    for (auto p:at) {
        int x=p.first, y=p.second;
        int cnt=0;
        for(int i=0; i<3; i++) {
            for(int j=0; j<3; j++) {
                int xx=x+i, yy=y+j;
                auto q=P(xx,yy);
                auto it=lower_bound(v.begin(), v.end(), q);
                if ( it==v.end() ) continue;
                if ( *it==q ) cnt++;
            }
        }
        ans[cnt]++;
    }

    for (int i=0; i<10; i++) {
        cout << ans[i] << '\n';
    }

    return 0;
}
