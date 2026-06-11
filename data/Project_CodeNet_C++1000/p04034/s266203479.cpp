#include <bits/stdc++.h>
 
using namespace std;
typedef long long ll;
typedef vector<int> VI;
ll mm=1000000000;ll MM=mm+7;
#define rep(i, n) for(int i=0;i<n;i++)
#define PI 3.141592653589793

int main(){
    int n,m;
    cin >> n>> m;
    VI x(m);
    VI y(m);
    rep(i,m){
        cin >> x.at(i) >> y.at(i);
    }
    map<int ,int > box;
    rep(i,n){
        box[i+1]=1;
    }
    set< int >  chk;
    chk.insert(1);
    rep(i,m){
        box.at(x.at(i))--;
        box.at(y.at(i))++;
        if(chk.count(x.at(i))){
            chk.insert(y.at(i));
            if(box.at(x.at(i))==0){
                chk.erase(x.at(i));
            }
           
        }

    }
    int ans=chk.size();
    cout << ans << endl;
}