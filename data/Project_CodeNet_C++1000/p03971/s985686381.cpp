#include <bits/stdc++.h>

#define PI 3.14159265359
#define rep(i,a,n) for(int i=a;i<(int)n;++i)
#define SZ(x) ((int)(x).size())	//size() unsigned -> int
#define descSort(a) sort(a.begin(),a.end(),std::greater<int>())
using namespace std;
typedef long long ll;
const ll INF = 1e9 + 7;

int main() {
    int n,a,b;
    string s;
    cin>>n>>a>>b>>s;

    int kaigai=1,kakutei=1;
    rep(i,0,n){
        if(s[i]=='a'){
            if(kakutei<=a+b){
                cout<<"Yes"<<endl;
                kakutei++;
            }else cout<<"No"<<endl;
        }
        else if(s[i]=='b'){
            if(kakutei<=a+b && kaigai<=b){
                cout<<"Yes"<<endl;
                kakutei++;
                kaigai++;
            }else cout<<"No"<<endl;
        }
        else cout<<"No"<<endl;
    }
    return 0;
}