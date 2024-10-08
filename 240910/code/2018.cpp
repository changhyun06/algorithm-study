#include <iostream>

using namespace std;

int main()
{
  int n;
  int sum = 0;
  int cnt = 0;

  cin >> n;

  for (int j = n - 1; j >=0; j--)
  {
    sum=0;
    for (int i = j; i >= 0; i--)
    {
      if (sum > n)
      {
        break;
      }
      else if (sum == n)
      {
        cnt++;
        break;
      }
      else
      {
        sum += i;
      }
    }
  }

  cout << cnt + 1;
}