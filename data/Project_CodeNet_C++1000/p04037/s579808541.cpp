#include <iostream>
#include <vector>
#include <string>
#include <cmath>
#include <algorithm>
#include <utility>
#include <queue>
#include <set>
#include <map>
#include <deque>
#include <iomanip>
#include <cstdio>
#include <stack>
#include <numeric>
#include <cassert>
using namespace std;
typedef  long long ll;
typedef pair<int,int> PII;
typedef vector<int> VI;
typedef vector<VI> VVI;
#define  MP make_pair
#define  PB push_back
#define inf 1000000007
#define mod 1000000007
#define rep(i,n) for(int i=0;i<(int)(n);++i)

int main(){
    int n;
    cin >> n;
    vector<int>a(n);
    rep(i,n){
        cin >> a[i];
    }
    sort(a.begin(),a.end());
    int h = a[0];
    bool p = 0;
    for(int i=1;i<n;i++){
        if(a[i]==a[i-1]){
            p = !p;
        }else{
            bool q = (a[i]-h)%2;
            if(q){
                if(p){
                    if(h+i==n||h+i-1==n){
                        cout << "First" << endl;
                        return 0;
                    }else if(h+i-1>n){
                        int k = h-2+i-n+1;
                        cerr << "test 1" << " "  << k << endl;
                        if(k%2==1){
                            cout << "Second" << endl;
                        }else{
                            cout << "First" << endl;
                        }
                        return 0;
                    }
                }
            }else{
                if(!p){
                    if(h+i==n||h+i+1==n){
                        cout << "First" << endl;
                        return 0;
                    }else if(h+i>n){
                        int k = h-1+i-n+1;
                        cerr << "test 2" << " " << k << endl;
                        if(k%2==1){
                            cout << "Second" << endl;
                        }else{
                            cout << "First" << endl;
                        }
                        return 0;
                    }
                }
            }
            h = a[i];
            p = 0;
        }
    }
    if(((a[n-1]%2==0)^p)){
        cout << "First" << endl;
    }else{
        cout << "Second" << endl;
    }

    return 0;
}