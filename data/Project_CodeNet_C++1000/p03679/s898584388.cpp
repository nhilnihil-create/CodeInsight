#include<iostream>
#include<algorithm>
#include<cmath>
#include<vector>
#include<queue>

using namespace std;

#define int long long
#define REP(i,s,e) for((i)=(s);(i)<(e);(i)++)
#define RREP(i,s,e) for((i)=((s)-1);(i)>=(e);(i)--)

signed main(){
    int X,A,B;

    cin>>X>>A>>B;

    if(B-A<=X&&B-A>0) cout<<"safe"<<endl;
    else if(B-A<=0) cout<<"delicious"<<endl;
    else cout<<"dangerous"<<endl;
}

