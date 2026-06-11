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
#define M (998244353)
#define INF 1e16
typedef long long ll;
typedef pair<int,int> P;
 

int  A(int x){
    if(x>=0)return x;
    else return -x;
}


int main(void){
    int a,b,c;
    cin>>a>>b>>c;
    if(a+b == c || b+c == a || c+a == b){
        cout<<"Yes"<<endl;
    }
    else cout<<"No"<<endl;
    return 0;
}