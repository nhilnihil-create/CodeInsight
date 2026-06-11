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

int n,k,d[12];

int main()
{
    ///freopen("INA.txt","r",stdin);
    ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);

    cin>> n >> k;

    for(int i=1;i<=k;i++){
        int a;
        cin>> a;
        d[a]=1;
    }

    for(int i=n;i<=99999;i++){
        int num=i,f=1;
        while(num!=0){
            int digit = num%10;
            num/=10;
            if(d[digit]==0){
                f=1;
            }
            else{
                f=0;
                break;
            }

        }
        if(f==1){
            cout<< i << endl;
            break;
        }
    }


    return 0;
}

