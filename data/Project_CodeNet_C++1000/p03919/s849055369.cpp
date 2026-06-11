#include <iostream>
#include <vector>
#include <map>
#include <cstdio>
#include <cstring>
#include <math.h>
#include <bitset>
#include <time.h>
#include <set>
#include <algorithm>
#define MODD 1000000007
#define ll long long
using namespace std;

int main() {
    int N,M;
    cin>>N>>M;
    string ans;
    for(int i=0;i<N;i++)
        for(int j=0;j<M;j++)
        {
            string S;
            cin>>S;
            if (S=="snuke") {
                printf("%c%d\n",j+'A',i+1);
            }
        }
}