#include <iostream>

using namespace std;

int main()
{
  int max = 0;
  int index = 0;
  int a;

  for (int i = 0; i < 9; i++)
  {
    cin >> a;
    if (max < a)
    {
      max = a;
      index = i + 1;
    }
  }

  cout << max << '\n' << index;
}