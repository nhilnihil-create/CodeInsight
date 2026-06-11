#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
using Graph = vector<vector<int>>;
const int INT_INF = 1001001001;

int main(){
    int n;
    cin >> n;
    vector<ll> A(n);
    for(int i=0;i<n;i++){
        cin >> A[i];
    }
    map<ll,int> m;
    for(int i=0;i<n;i++){
        m[A[i]]++;
    }

    vector<ll> q(1,0);

    vector<ll> p(2,0);
    for(auto x:m){
        if(x.second >= 4){
            q.push_back(x.first);
        }
        if(x.second >= 2){
            p.push_back(x.first);
        }
    }
/*
    for(auto x:p){
        cout << x << " ";
    }
    cout << endl;

    for(auto x:q){
        cout << x << " ";
    }
    cout << endl;
*/
    sort(q.begin(),q.end(),greater<ll>());
    sort(p.begin(),p.end(),greater<ll>());

/*
    for(auto x:p){
        cout << x << " ";
    }
    cout << endl;

    for(auto x:q){
        cout << x << " ";
    }
    cout << endl;
*/

    cout << max(q[0]*q[0],p[0]*p[1]) << endl;
    
}