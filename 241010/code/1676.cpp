#include <iostream>
#include <string>

using namespace std;

int main()
{
  int n;
  int cnt = 0;
  int a[2] = {
      0,
  };

  cin >> n;

  for (int i = 1; i <= n; i++)
  {
    int tmp = i;
    while (true)
    {
      if (tmp % 2 == 0)
      {
        tmp /= 2;
        a[0]++;
      }
      else if (tmp % 5 == 0)
      {
        tmp /= 5;
        a[1]++;
      }
      else
      {
        break;
      }
    }
  }

  if (a[0] < a[1])
  {
    cout << a[0];
  }
  else
  {
    cout << a[1];
  }
}