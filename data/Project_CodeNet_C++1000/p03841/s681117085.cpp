#include <iostream>
#include <vector>
#include <string>
#include <cmath>
#include <algorithm>
#include <utility>
#include <queue>
#include <set>
#include <map>

using namespace std;
typedef  long long ll;
typedef pair<int,int> PII;
typedef vector<int> VI;
typedef vector<VI> VVI;
#define  MP make_pair
#define  PB push_back
#define inf  1000000007
#define rep(i,n) for(int i=0;i<(int)(n);++i)

template<typename A, size_t N, typename T>
void Fill(A (&array)[N], const T &val){
    std::fill( (T*)array, (T*)(array+N), val );
}

int main(){
    int n;
    cin >> n;
    vector<int>x(n);
    vector<int>y(n*n);
    vector<int>a(n*n);
    rep(i,n)cin >> x[i],a[x[i]-1] = i+1,y[x[i]-1] =i+1;
    priority_queue<pair<int,int>,vector<pair<int,int> >,greater<pair<int,int> > > pq,pq2;
    rep(i,n)pq.push(MP(x[i]-1,i+1)),pq2.push(MP(x[i]-1,i+1));
    int t = 0;
    bool flag = 0;
    while(!pq.empty()){
        auto p = pq.top();
        pq.pop();  
        int z = 1;
        while(z < p.second){
            if(t > p.first){
                flag = 1;
                break;
            }
            if(a[t]!=0){
                t++;
            }else{
                z++;
                a[t] = p.second;
            }
        }

        if(flag)break;
    }
    
    vector<int>s(n+1);
    rep(i,n+1)s[i] = i;
    while(!pq2.empty()){
        auto p = pq2.top();
        pq2.pop();
        while(s[p.second]<n){
            if(a[t]==0){
                a[t] = p.second;
                s[p.second]++;
                t++;
            }else{
                t++;
            }
        }
    }
    vector<int> q(n+1);
    rep(i,n*n){
        q[a[i]]++;
        if(y[i]!=0){
            if(q[a[i]]!=a[i])flag = 1;
        }
    }
    if(flag){
        cout << "No" << endl;
    }else{
        cout << "Yes" << endl;
        rep(i,n*n){
            cout << a[i];
            if(i!=n*n-1)cout << " ";
        }
        cout << endl;
    }
    return 0;
}