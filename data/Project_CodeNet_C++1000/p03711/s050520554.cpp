#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i,n) for (int i = 0; i < (n); ++i)
#define rep2(i,a,b) for (int i = (a); i < (b); ++i)


int main(){
    int x,y;
    cin>>x>>y;

    vector<int> v1 = {1,3,5,7,8,10,12};
    vector<int> v2 = {4,6,9,11};

    if ( (find(v1.begin(), v1.end(), x)!=v1.end() && find(v1.begin(), v1.end(), y)!=v1.end() )
           || (find(v2.begin(), v2.end(), x)!=v2.end() && find(v2.begin(), v2.end(), y)!=v2.end() )) cout<<"Yes"<<endl;
    else cout<<"No"<<endl;


    return 0;
}
