#include<iostream>
#include<vector>
#include<cstdio>
#include<string>
#include<numeric>
#include<algorithm>
#include<complex>
#include<queue>
#include<stdlib.h>
#include<map>
#include<cmath>
#include<stdio.h>
#include<stdlib.h>
#include<set>

#define ll long long int
#define MOD 1000000007

using namespace std;

int main(){
    string S;
    cin >> S;
    string S2 = "CODEFESTIVAL2016";
    int def=0;
    for(int i=0;i<S.size();i++){
        if(S[i]!=S2[i]){
            def++;
        }
    }
    cout << def << endl;
    return 0;
}
