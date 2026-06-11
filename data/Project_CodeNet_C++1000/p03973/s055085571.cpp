#include <iostream>
#include <map>
#include <vector>
#define lli long long int
using namespace std ;


int main(int argc, char const *argv[])
{

	int n ;
	cin>>n ;
	lli ans = 0 ;
	int carry ;
	for(int i = 0 ; i < n ; i++)
	{
		int temp ;
		cin>>temp ;
		if(i == 0)
		{
			 carry = 1 ;
			if(temp == 1) ;
			else
			{
				ans+=temp-1 ;
			}
			continue ;
		}

		if(temp <= carry) continue ;

		if(temp == carry + 1)
		{
			++carry ;
			continue ;
		}

		if(temp %(carry + 1) == 0)
		{
			++carry ;
			ans+= (temp/carry) ;
			--ans ;
			--carry ;
			continue ;
		}

		else
		{
			++carry ;
			ans+= (temp/carry) ;
			--carry ;

		}

	}

	cout<<ans<<endl ;



	return 0;
}