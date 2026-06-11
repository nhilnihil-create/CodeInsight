#include <bits/stdc++.h>
using namespace std;

int main() {
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif

    std::ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    cout.tie(NULL);

    int a,b,c;
    cin>>a>>b>>c;
    if ((a==5 && b==5 && c==7) ||(a==5 && b==7 && c==5) || (a==7 && b==5 && c==5))
    {
    	cout<< "YES"<<endl;
    }
    else{
    	cout<< "NO"<<endl;
    }

}
