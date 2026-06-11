#include<bits/stdc++.h>
#define range(i,a,b) for(int i = (a); i < (b); i++)
#define rep(i,b) for(int i = 0; i < (b); i++)
#define all(a) (a).begin(), (a).end()
#define show(x)  cerr << #x << " = " << (x) << endl;
#define debug(x) cerr << #x << " = " << (x) << " (L" << __LINE__ << ")" << " " << __FILE__ << endl;
const int INF = 2000000000;
using namespace std;

int main(){
    int n;
    cin >> n;

    int i = 0;
    while((1 + i) * i / 2 < n){
        i++;
    }

    vector<int> v;
    for(int j = i; i >= 0; i--){
        if(n >= i){
            n-=i;
            v.emplace_back(i);
        }
        if(n == 0) break;
    }

    for(int j = v.size() - 1; j >= 0; j--){
        cout << v[j] << endl;
    }
}
