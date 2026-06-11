#include <bits/stdc++.h>
using namespace std;

int W,H,N;
int x[110],y[110],a[110];

int main()
{
    cin>>W>>H>>N;

    int left=0,right=W,top=H,bottom=0;
    for (int i = 0; i < N; i++)
    {
        cin>>x[i]>>y[i]>>a[i];
    }

    for (int i = 0; i < N; i++)
    {
        if(a[i] == 1){
            if(x[i]>=left) left = x[i];
        } else if(a[i] == 2){
            if(x[i]<=right) right = x[i];
        } else if(a[i] == 3){
            if(y[i]>=bottom) bottom = y[i];
        } else {
            if(y[i]<=top) top = y[i];
        }
    }
    
    if((right-left)>0 && (top-bottom)>0){
        cout << (right-left) * (top-bottom) << endl;
    } else {
        cout << 0 << endl;
    }
    
    return 0;
}
