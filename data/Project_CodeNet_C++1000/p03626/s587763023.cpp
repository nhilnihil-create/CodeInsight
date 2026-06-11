#include <iostream>
#include <vector>
#include <string>
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

typedef long long LL;
//typedef long double LD;
using namespace std;
 
#define MOD 1000000007
//#define MAX 100100
//#define NIL -1

int main(){
    int n;
    string s1;
    string s2;
    LL ans=1;
    vector<int> pat;

    cin >> n;
    cin >> s1;
    cin >> s2;

    int i=0;
    while(i<n){
        if(s1[i]==s2[i]){
            pat.push_back(1);
            i++;
        }else{
            pat.push_back(0);
            i+=2;
        }
    }

    if(pat[0]==0){
        ans=ans*3*2;
    }else{
        ans=ans*3;
    }

    //for(int i=0; i<pat.size(); i++){
    //    cout << pat[i];
    //}
    //cout << endl;

    for(int i=1; i<pat.size(); i++){
        if(pat[i-1]==0){
            if(pat[i]==0){
                ans=(ans*3)%MOD;
            }else{
                ans=ans%MOD;
            }
        }else{
            ans=(ans*2)%MOD;
        }
        //cout << i << " " << ans << endl;
    }
    cout << ans << endl;

    return 0;
}
