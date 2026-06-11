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
    if(a[n-1]-a[0]>1){
        cout << "No" << endl;
    }else if(a[n-1]-a[0]==0){
        if(a[0]==n-1){
            cout << "Yes" << endl;
        }else if(a[0]>n/2){
            cout << "No" << endl;
        }else{
            cout << "Yes" << endl;
        }
    }else{
        int c = 0;
        rep(i,n){
            if(a[i]==a[0]){
                c++;
            }
        }
        if(a[0]>=c&&a[0]<c+(n-c)/2){
            cout << "Yes" << endl;
        }else{
            cout << "No" << endl;
        }
    }

    return 0;
}