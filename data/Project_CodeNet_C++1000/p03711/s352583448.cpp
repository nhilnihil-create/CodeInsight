 #include<bits/stdc++.h>
using namespace std;
long A[22];
int main()
{
   long long a,i;
    A[1]=A[3]=A[5]=A[7]=A[8]=A[10]=A[12]=100;
    A[4]=A[6]=A[9]=A[11]=50;
    A[2]=75;
    cin>>a>>i;
    if(A[a]==A[i]) std::cout << "Yes" << '\n';
    else std::cout << "No" << '\n';
}
