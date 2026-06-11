#include <bits/stdc++.h>
using namespace std;

int main()
{
    int X;
    cin>>X;
    for(int i=1;;i++){
        int k=i*(i+1)/2;
        if(k>=X){
            cout<<i;
            return 0;
        }
    }

}
