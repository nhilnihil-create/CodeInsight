#include<iostream>
#include<algorithm>
#include<vector>
#include<string>
#include<utility>
#include<map>
#include<set>
#include<queue>
#include<stack>
#include<functional>
#include<math.h>
using namespace std;
#define N (1000000000+7)
#define INF 1e16
typedef long long ll;
typedef pair<ll,ll> P;
 

int main(void){
    string s;
    cin>>s;
    for(int i=0;i<s.length();i++){
        if(i==3)cout<<s[i]<<" ";
        else cout<<s[i];
    }
    cout<<endl;
    return 0;
}