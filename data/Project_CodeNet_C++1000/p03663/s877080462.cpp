#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <algorithm>
#include <set>
#include <map>
#include <cmath>
#include <cstring>
using namespace std;

#define fi first
#define se second
typedef long long LL;
typedef long double LD;


bool ask(LL x){
    cout << "? " << x << "\n";
    cout.flush();

    char ans;
    cin >> ans;
    return (ans=='Y');
}

void print_ans(LL x){
    cout << "! " << x << "\n";
    cout.flush();
}

int main(){


    int len=1,i; LL val=1;
    for (i=1; i<=12; i++){
        if (ask(val)) len=i;
        else break;
        val*=10;
    }

    if (len==12){
        val=9;
        while (!ask(val))
            val*=10;

        print_ans(val/9);
        return 0;
    }

    val=0;
    for (i=1; i<len; i++){
        int l=(i==1 ? 1 : 0),r=9,mid;

        val*=10;
        while (l<r){
            mid=(l+r+1)/2;
            if (ask(val+mid)) l=mid;
            else r=mid-1;
        }

        val+=r;
    }

    int l=(len==1 ? 1 : 0),r=9,mid;
    while (l<r){
        mid=(l+r)/2;
        if (ask(val*100+mid*10+1)) r=mid;
        else l=mid+1;
    }

    val=val*10+r;

    print_ans(val);
    return 0;
}
