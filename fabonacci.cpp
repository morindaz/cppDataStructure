
#include<iostream>
using namespace std;

int fabonacci(int n)
{

  if(n==1||n==0)
    return 1;
  else
  {
      return fabonacci(n-2)+fabonacci(n-1);
  }

}

int main()
{
    int a ;
    a = fabonacci(2);
    cout<<a;

}
