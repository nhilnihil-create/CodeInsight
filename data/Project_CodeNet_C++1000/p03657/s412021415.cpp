#include<iostream>
#include<vector>
#include<algorithm>
#include<queue>
#include<iomanip>
#include <math.h>
using namespace std;
int main(){
    int n,m;
    string s="Impossible";
    cin>>n>>m;
    if(n%3==0||m%3==0||((n+m)%3==0)){
        s="Possible";
    }
    cout<<s<<endl;
    
    return 0;
}
