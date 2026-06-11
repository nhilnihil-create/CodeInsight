#include <cstdio>
#include <iostream>
#include <iomanip>
#include <string>
#include <cmath>
#include <vector>
using namespace std;

int main() {
    int N=0;
    cin>>N;
    long long count=0;
    for(int i=0;i<N;i++){
      long long a,b;
      cin>>a>>b;
      count+=b-a+1;
    }
    cout<<count<<endl;
    return 0;
}