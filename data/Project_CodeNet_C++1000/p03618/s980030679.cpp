#include <bits/stdc++.h>
#include <iostream>
#include <string>
#include <vector>
#define MOD 1000000007
#define INT long long int
#define REP(i,n) for(int(i)=0;(i)<(n);(i)++) 
using namespace std;
const long long INF = numeric_limits<long long>::max();
#include <map>
#include <fstream>

int main()
{   
    string S;
    cin>>S;
    // ifstream ifs("in.txt");
    // while(getline(ifs,S));
    map<char, INT> counter;
    INT N = S.size();
    REP(i,N){
        counter[S[i]]++;
    }
    INT ans = N*(N-1)/2+1;
    for (pair<char,INT> cnt:counter){
        INT minus =(cnt.second*(cnt.second-1))/2; 
        ans -= minus;
    }
    cout<<ans<<endl;

    return 0;
}