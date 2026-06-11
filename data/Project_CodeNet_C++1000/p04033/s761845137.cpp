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


int main(void){
    int a,b;
    cin>>a>>b;
    if(a>0)cout<<"Positive"<<endl;
    else{
        if(a==0)cout<<"Zero"<<endl;
        else{
            if(b>=0)cout<<"Zero"<<endl;
            else{
                if((b-a+1)%2==0)cout<<"Positive"<<endl;
                else cout<<"Negative"<<endl;
            }
        }
    }
    return 0;
}