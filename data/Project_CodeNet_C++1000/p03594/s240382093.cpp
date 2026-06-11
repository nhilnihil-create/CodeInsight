#include <bits/stdc++.h>
using namespace std;

#define REP(i,n) for(decltype(n) i=0; i<(n); ++i)
#define ALL(c) (c).begin(), (c).end()
#define st first
#define nd second
#define pb push_back

typedef pair<int,int> pii;
typedef vector<int> vi;
typedef vector<vector<int>> vvi;
typedef long long ll;

void solve(){
    int h,w,d;
    cin>>h>>w>>d;
    const char colors[] {'R','G','B','Y'};
    for(int i=0;i<h;++i){
        for(int j=0;j<w;++j){
            int a = j+i;
            int b = j-i;
            a %= 2*d;
            if(b<0) b=2*d-(-b)%(2*d);
            b %= 2*d;
            int color = 0;
            if(a >= d)
                color += 1;
            if(b >= d)
                color += 2;
            cout<<colors[color];
        }
        cout<<'\n';
    }
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    solve();
    return 0;
}
