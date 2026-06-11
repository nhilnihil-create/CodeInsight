#include <iostream>
#include <string>
#include <vector>
#include <utility>
#include <functional>
#include <numeric>
#include <list>
#include <set>
#include <map>
#include <algorithm>
#include <cmath>
#include <limits>
#include <iomanip>
#include <bitset>
#include <queue>
#include <unordered_set>

using namespace std;
typedef long long ll;

template<class T>bool chmax(T &a, const T &b) { if (a<b) { a=b; return 1; } return 0; }
#define rep(i, n) for(int i = 0;i < n;i++)
const int INF = 1LL << 30;

int MOD = 1000000007;

int main(){
    std::ios_base::sync_with_stdio(false);
    cin.tie(0);

    int n,x; cin >> n >> x;

    int m=n*2-1;

    if(n==2 && x==2){
        cout << "Yes" << endl;
        cout << 1 << endl;
        cout << 2 << endl;
        cout << 3 << endl;

        return 0;

    }else{
        if(x>2 && m-x>=1){
            cout << "Yes" << endl;
            std::vector<int>  arr(m,0);

            arr[m/2]=x;
            arr[m/2-1]=x-1;
            arr[m/2+1]=x+1;
            arr[m/2+2]=x-2;

            std::vector<int> rest;
            rep(i,m){
                if((i+1)>x+1 || (i+1)<x-2) rest.push_back(i+1);
            }

            int j = 0;
            rep(i,m){
                if(arr[i]==0) arr[i] = rest[j++];
            }

            rep(i,m) cout << arr[i] << endl;
            return 0;

        } else if(x>1 && m-x>=2){
            cout << "Yes" << endl;
            std::vector<int>  arr(m,0);

            arr[m/2]=x;
            arr[m/2-1]=x+1;
            arr[m/2+1]=x-1;
            arr[m/2+2]=x+2;

            std::vector<int> rest;
            rep(i,m){
                if((i+1)>x+2 || (i+1)<x-1) rest.push_back(i+1);
            }

            int j = 0;
            rep(i,m){
                if(arr[i]==0) arr[i] = rest[j++];
            }

            rep(i,m) cout << arr[i] << endl;
            return 0;
        }
    }

    cout << "No" << endl;
    return 0;
}