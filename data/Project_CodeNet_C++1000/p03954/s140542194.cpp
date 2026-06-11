#include <bits/stdc++.h>
using namespace std;

int n;
vector <int> a;

bool one(int x){
    vector <bool> b;
    for(int&i : a)
        b.push_back(i<=x);
    //cout << x << " = " << b[n-2] << ' ' << b[n-1] << ' ' << b[n] << endl;
    if(b[n-1]==b[n-2] || b[n-1]==b[n])
        return b[n-1];
    int left = 0 ,right = 0;
    for(int i=n-2; ~i; i--){
        if(b[i] == b[i+1])
            break;
        left++;
    }
    for(int i=n; i<2*n-1; i++){
        if(b[i] == b[i-1])
            break;
        right++;
    }
    if(left < right)
        return b[n-1-left];
    if(right < left)
        return b[n-1+right];
    return (left&1) ? !b[n-1] : b[n-1];
}

int main()
{
    scanf("%d",&n);
    a.resize(2*n-1);
    for(int&i : a)
        scanf("%d",&i);

    int st = 1 ,en = 2*n-1 ,mid;
    while(st <= en){
        mid = (st+en)>>1;
        if(one(mid))
            en = mid-1;
        else
            st = mid+1;
    }

    printf("%d\n",st);
}
