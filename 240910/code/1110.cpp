#include <iostream>

using namespace std;

int main()
{
  int n;
  int r1 = 0, r2 = 0; // r1은 전 숫자, r2는 계산하는 숫자
  int cnt = 0;

  cin >> n;
  r1 = n;
  r2 = n;

  do
  {
    r2 = (r1 % 10 * 10) + (r2 / 10 + r2 % 10) % 10;

    r1 = r2;

    cnt++;
  } while (r2 != n);

  cout << cnt;
}