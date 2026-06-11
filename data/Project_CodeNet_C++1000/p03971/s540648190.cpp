#include <iostream>
#include <algorithm>
#include <bitset>
#include <tuple>
#include <cstdint>
#include <cstdio>
#include <cctype>
#include <assert.h>
#include <stdlib.h>
#include <stdio.h>
#include <cassert>
#include <cfloat>
#include <climits>
#include <cmath>
#include <complex>
#include <ctime>
#include <deque>
#include <fstream>
#include <functional>
#include <iomanip>
#include <iostream>
#include <iterator>
#include <list>
#include <limits>
#include <map>
#include <memory>
#include <queue>
#include <random>
#include <set>
#include <stack>
#include <string>
#include <unordered_map>
#include <unordered_set>
#include <utility>
#include <vector>
#include <math.h>
#define int long long
using namespace std;
signed main() {
	int N,A,B;
    cin>>N>>A>>B;
 
    vector<char>S(N);
    int X=A+B;
    int Y=0;
    for(int i=0;i<N;i++){
        cin>>S[i];
    }
    for(int i=0;i<N;i++){
        if(S[i]=='c'){
            cout<<"No"<<endl;
        }
        else if(S[i]=='a'){
            X--;
            if(X>=0){
                cout<<"Yes"<<endl;
            }
            else{
                cout<<"No"<<endl;
            }
        }
        else{
            Y++;
            if(X>0&&Y<=B){
                cout<<"Yes"<<endl;
                X--;
            }
            else{
                cout<<"No"<<endl;
            }
        }
    }   
}