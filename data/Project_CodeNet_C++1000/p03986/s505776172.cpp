#include<iostream>
#include<string>
#include<stack>
using namespace std;
 
int main()
{
    string a;
    cin>>a; 
    int sz= a.size();
    
    stack<char> st;
    for ( int i = 0 ; i < a.size() ; i ++ )
	{
        if ( a[i] == 'T' )
		{
            if ( !st.empty() )
			{
                if (st.top() == 'S' )
				{
                    sz -= 2 ;
                    st.pop() ;
                }
            }
			else
                st.push(a[i]) ;
        }
		else
            st.push(a[i]) ;
    }
    cout << sz << endl ;
   
    return 0 ;
}