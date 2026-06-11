#include<bits/stdc++.h>
using namespace std;
int main()
{
  long long n,ans=0,x;
  cin>>x;//读入
  n=ceil(x/11.0);
  //此处的'ceil'为向上取整符，而为了防止括号内自动向下取整，
  //需要加上.0来强制转换为浮点型
  ans=ceil(x/11.0)*2;
  //因为每一大轮其实是两轮，所以要乘2
  if(n*11-x>=5)//如果可以省略最后掷的五分
    ans--;//答案减一
  cout<<ans<<endl;//输出
  return 0;
}