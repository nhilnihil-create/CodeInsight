#include <bits/stdc++.h>
using namespace std;
int main()
{
	long long N, A, B, ans;    
	cin >> N >> A >> B;
    if(A>B) 
		cout << 0;
    else if(A==B)    
		cout << 1;
    else
	{
        if(N==1)    
			cout << 0;
        else if(N==2)   
			cout << 1;
        else
		{
            ans = B*(N-1)+A - A*(N-1) -B + 1;
            cout << ans;
        }
    }
}
