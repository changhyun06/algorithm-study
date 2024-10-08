#include <iostream>
#include <algorithm>

using namespace std;

int main()
{
  int n;
  int a[50] = {
      0,
  };
  int max = 0;
  int cnt = 0;

  cin >> n;

  cin >> a[0];

  for (int i = 1; i < n; i++)
  {
    cin >> a[i];
    if (max < a[i])
    {
      max = a[i];
    }
  }

  if (n != 1)
  {
    int me = a[0];

    while (me <= max) //다솜이의 표가 다솜이를 제외한 가장 많은 사람보다 작을 경우
    {
      sort(a + 1, a + n);
      max = a[n - 1];
      me += 1; //다솜이의 표를 +1
      a[n - 1] -= 1; //가장 많은 사람의 표수를 -1
      sort(a + 1, a + n);
      max = a[n - 1];
      cnt++;
    }
  }

  cout << cnt;
}