#include <iostream>
#include <algorithm>

using namespace std;

int main()
{
  string n;

  cin >> n;

  sort(n.begin(), n.end(), greater<int>());

  cout << n;
}