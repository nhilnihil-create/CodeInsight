#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 1; i <= (n); i++)
#define MOD 1000000007
using ll = long long;
typedef pair<int, int> P;

int main(){
    int a,b,c;
    cin>>a>>b>>c;
    if(b>=c){
        cout<<"delicious"<<endl;
        return 0;
    }
    if(c-b<=a){
        cout<<"safe"<<endl;
        return 0;
    }
    cout<<"dangerous"<<endl;
    return 0;
}