#include <iostream>
#include <vector>
//#include <string>
//#include <algorithm>
//#include <math.h>
//#include <queue>
//#include <stack>
//#include <iomanip>

// sometimes used
//#include <set>
//#include <map>
//#include <numeric>
//#include <list>
//#include <deque>
//#include <unordered_map>

//typedef long long LL;
//typedef long double LD;
using namespace std;
 
//#define MOD 1000000007
//#define MAX 100100
#define NIL -1

int main() {
    int a;
    int b;
    int c;
    int d;
    int e;
    int f;
    vector<int> g(31, NIL);
    cin >> a >> b >> c >> d >> e >> f;

    int tmp;

    for(int i=0; 100*a*i<=f; i++){
        for(int j=0; 100*b*j<=f; j++){
            if(100*(a*i+b*j)<f){
                g[a*i+b*j]=1;
                tmp=a*i+b*j;
            }
        }
    }

    int max_num=0;
    double max_val=0.0;
    int max_idx=NIL;
    for(int i=1; i<=30; i++){
        if(g[i]!=NIL){
            for(int j=0; c*j<=f; j++){
                for(int k=0; d*k<=f; k++){
                    if(c*j+d*k<=e*i && 100*i+c*j+d*k<=f){
                        if((double)(c*j+d*k)/(((double)i*100.0+(double)(c*j+d*k)))>max_val){
                            max_val=(double)(c*j+d*k)/(((double)i*100.0+(double)(c*j+d*k)));
                            max_num=c*j+d*k;
                            max_idx=i;
                            //cout << max_val << endl;
                        }
                    }
                }
            }
        }
    }

    if(max_num==0){
        max_idx=tmp;
    }

    cout << max_idx*100+max_num << " " << max_num << endl;

    return 0;
}