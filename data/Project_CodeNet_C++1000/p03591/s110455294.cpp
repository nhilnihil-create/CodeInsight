#include <bits/stdc++.h>
#define be(v) (v).begin(),(v).end()
#define pb(q) push_back(q)
typedef long long ll;
using namespace std;
const ll mod=1000000007;
#define doublecout(a) cout<<fixed<<setprecision(10)<<a<<endl;

int main() {
    cin.tie(0);
    cout.tie(0);
    ios::sync_with_stdio(false);
    string s;
    cin>>s;
    int n=s.length();
    if(n>=4&&(s.substr(0,4)=="YAKI")){
        cout<< "Yes"<<endl;
    }else{
        cout << "No" <<endl;
    }
    return 0;
}
