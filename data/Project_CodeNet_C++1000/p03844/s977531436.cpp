#include <bits/stdc++.h>

using namespace std;




int main(void)
{
    int A,B,ans;
    char op;

    cin>>A>>op>>B;
    
    switch (op)
    {
    case '+'/* constant-expression */:
        /* code */
        ans=A+B;
        break;
    
    default:
    ans=A-B;
        break;
    }


    cout<<ans<<endl;

	return 0;
}
