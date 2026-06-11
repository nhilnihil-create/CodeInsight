#include <cstdio>
#include <string>
#include <cmath>
#include <iostream>
using namespace std;


int a[50];
int main(){
    long long N;
    scanf("%lld",&N);
    N++;
    int op = log2(N);
    int cnt = 0;
    while (N){
        a[op-cnt] = N&1;
        N>>=1;
        cnt ++;
    }
    //for (int i=0;i<=op;i++) printf("%d ",a[i]);

    string l = "";
    string r = "";
    cnt = 0;
    int len = 0;
    for (int i=1;i<=op;i++){
        string s = to_string(++cnt);
        l = l+" "+s;
        r = r+" "+s;
        len+=2;
        if (a[i]){
            string s = to_string(++cnt);
            l = s+" "+l;
            r = r+" "+s;
            len+=2;
        }



    }
    cout << len << endl;
    cout << l+" "+r << endl;
    return 0;
}

