#include<bits/stdc++.h>

using namespace std;

int main()
{
    int n,m,a,b;
    cin >> n >> m;
    vector<bool> vb(n+1, false);
    bool ans = false;
    for(int i=0;i<m;i++)
    {
      //  int a,b;
        cin >> a >> b;
       // assert(1 <= a && a < b && b <= n);
        if(a==1)
        {
            if(vb[b]==true)
                ans=true;
            vb[b]=true;
        }
        else if(b==n)
        {
            if(vb[a]==true)
                ans=true;
            vb[a]=true;
        }
    }
    if(ans)
        cout << "POSSIBLE\n";
    else
        cout << "IMPOSSIBLE\n";


    return 0;
}

