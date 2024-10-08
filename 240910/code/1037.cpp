#include <iostream>
#include<algorithm>

using namespace std;

int main()
{
  int n;
  int a[50] = {
      0,
  };

  cin >> n;

  for (int i = 0; i < n; i++)
  {
    cin >> a[i];
  }

  sort(a, a+n); //정렬하기

  cout << a[0] * a[n - 1]; //양끝쪽의 값을 곱해서 n 구하기
}