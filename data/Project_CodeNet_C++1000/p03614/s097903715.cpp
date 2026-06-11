#include<iostream>
#include<iomanip>
#include<cmath>
#include<string>
#include<vector>
#include<algorithm>
#include<map>
#include<set>
#include<queue>
#include<stack>
using namespace std;
typedef long long ll;
#define fi first
#define se second
#define mp make_pair
const int inf=1e9+7;
const ll mod=1e9+7;

int main() {
    int N;
    cin>>N;
    int p[N];
    for(int i=0;i<N;++i){
        cin>>p[i];
        p[i]--;
    }
    int ans = 0;
    int index = 0;
    while(index < N){
        if(p[index]==index){
            ans++;
            index += 2;
        }
        else index++;
    }
    cout<<ans<<endl;
}

