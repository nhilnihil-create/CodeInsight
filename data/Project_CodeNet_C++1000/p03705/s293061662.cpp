#include <bits/stdc++.h>

using namespace std;

int main() {
    long long N,A,B; 
    cin >>N>>A>>B;
    long long ans=B*(N-1)+A-A*(N-1)-B+1;
    if((N==1&&A!=B)||(A>B))ans=0;
    cout<<ans;
    return 0;
}