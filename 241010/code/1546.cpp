#include <iostream>

using namespace std;

int main()
{
  int n;
  double a[1000];
  int m = 0;
  double sum = 0;

  cin >> n;

  for (int i = 0; i < n; i++)
  {
    cin >> a[i];

    if (a[i] > m)
    {
      m = a[i];
    }
  }

  for (int i = 0; i < n; i++)
  {
    sum += a[i] / m * 100;
  }

  cout << sum / n;
}