#include <iostream>
#include <iomanip>
#include <vector>
#include <algorithm>
#include <stack>
#include <queue>
#include <limits.h>
#include <cmath>
#include <map>
using namespace std;
using P=pair<int,int>;
using ll=long long;
int main(){
    string t;
    cin>>t;
    int m=t.size();
    bool s=false,n=false,w=false,e=false;
    for(int i=0;i<m;i++){
        switch (t[i]){
            case 'S':
                s=true;
                break;
            case 'N':
                n=true;
                break;
            case 'W':
                w=true;
                break;
            case 'E':
                e=true;
                break;
        }
    }
    if(s!=n||w!=e)cout<<"No"<<endl;
    else cout<<"Yes"<<endl;
}