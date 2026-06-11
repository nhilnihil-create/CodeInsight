#include<bits/stdc++.h>
#define ll long long int
using namespace std;
bool cond;
ll N, L, a[100100], temp, knot, Ind, i;
int main(){
    cin >> N >> L;
    for(i=0;i<N;i++)
    {
        cin >> a[i];
        if(i>0)
            if(a[i]+a[i-1]>=L)
                cond = true, Ind = i;
    }
    if(cond)
    {
        cout << "Possible" << endl;
        for(knot = 1;knot<=N-1;knot++)
        {
            if(knot==Ind)
                break;
            cout << knot <<endl;
        }
        for(knot=N-1;knot>=Ind;knot--)
        {
            if(knot==Ind)
                break;
            cout << knot << endl;
        }
        cout << Ind << endl;
    }
    else{
        cout << "Impossible" << endl;
    }
}
