#include <iostream>
#include <string>
#include <vector>
#include <cmath>
#include <algorithm>
#include <iomanip>
using namespace std;
 
int main(){
    long Q,H,S,D;
    long N;
    long total=0;
    cin>>Q>>H>>S>>D>>N;
    total = (N/2)*min({8*Q,4*H,2*S,D})+(N%2)*min({4*Q,2*H,S});
    cout<<total<<endl;
}