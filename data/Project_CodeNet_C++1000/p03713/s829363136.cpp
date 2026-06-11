#include <iostream>
#include <vector>
//#include <string>
#include <algorithm>
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
 
//#define MOD 1000000007
//#define MAX 100100
#define NIL -1

int main() {
    LL h;
    LL w;
    cin >> h >> w;

    LL min_num1=h*w;
    LL min_num2=h*w;
    LL min_num3=h*w;
    LL min_num4=h*w;
    LL tmp1;
    LL tmp2;
    LL tmp3;
    LL tmp_diff;
    LL ans;
    if(h>=3){
        if(h%3==0){
            min_num1=0;
        }else{
            min_num1=w;
        }
    }

    for(int i=1; i<=w; i++){
        tmp1=i*h;
        if(h%2==0){
            tmp2=h/2*(w-i);
            tmp3=h/2*(w-i);
        }else{
            tmp2=(h/2+1)*(w-i);
            tmp3=h/2*(w-i);            
        }
        if(tmp1>tmp2){
            tmp_diff=tmp1-tmp3;
        }else{
            tmp_diff=tmp2-min(tmp1, tmp3);
        }
        if(min_num2>tmp_diff){
            min_num2=tmp_diff;
        }
    }

    if(w>=3){
        if(w%3==0){
            min_num3=0;
        }else{
            min_num3=h;
        }
    }

    for(int i=1; i<=h; i++){
        tmp1=i*w;
        if(w%2==0){
            tmp2=w/2*(h-i);
            tmp3=w/2*(h-i);
        }else{
            tmp2=(w/2+1)*(h-i);
            tmp3=w/2*(h-i);            
        }
        if(tmp1>tmp2){
            tmp_diff=tmp1-tmp3;
        }else{
            tmp_diff=tmp2-min(tmp1, tmp3);
        }
        if(min_num4>tmp_diff){
            min_num4=tmp_diff;
        }
    }

    ans = min(min(min_num1, min_num2), min(min_num3, min_num4));

    cout << ans << endl;

    return 0;
}