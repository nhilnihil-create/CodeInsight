#include <iostream>
#include <string>

int main()
{
	std::string A;
  	std::string B;
  	std::string C;
  	std::cin >> A >> B >> C;
  	int alice = 0;
  	int bob = 0;
  	int charlie = 0;
  	char last = 'a';
  	while(true)
    {
    	if(last == 'a')
        {
          	if(alice == A.size())
            {
            	std::cout << 'A';
              	return 0;
            }
          	last = A[alice];
          	++alice;
        }
      	else if(last == 'b')
        {
          	if(bob == B.size())
            {
            	std::cout << 'B';
              	return 0;
            }
        	last = B[bob];
          	++bob;
        }
      	else if(last == 'c')
        {
          	if(charlie == C.size())
            {
            	std::cout << 'C';
              	return 0;
            }
        	last = C[charlie];
          	++charlie;
        }
    }
  	return -1;
}