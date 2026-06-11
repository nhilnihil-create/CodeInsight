#include<iostream>
#include<algorithm>

long long A[1010190], souwa[123456];

int main(int argc, char *argv[])
{
  int n;
  std::cin >> n;
  for(int i=0;i<n;i++)
    std::cin >> A[i];
  std::sort(A,A+n,std::greater<long long>());
  souwa[n-1] = A[n-1];
  for(int i=n-2;i>=0;--i)
    souwa[i] = souwa[i+1] + A[i];
  int kotae = 1;
  for(int i=1;i<n;i++)
    {
      if( A[i-1] > souwa[i] * 2LL )
	break;
      kotae++;
    }
  std::cout << kotae << std::endl;
  return 0;
}
