#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <stack>
#include <map>
#include <cmath>
#include <cstdlib>
#include <cstring>
#include <cstdio>
#define ll long long int

using namespace std;

string s;
int a[30];

int main()
{
    ///freopen("INA.txt","r",stdin);
    ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);
    cin>> s;
    int ln = s.length();
    for(int i=0;i<ln;i++){
        a[s[i]-96]++;
    }
    for(int i=1;i<=26;i++){
        if(a[i]%2){
            cout<< "No" << endl;
            return 0;
        }
    }
    cout<< "Yes" << endl;

    return 0;
}

