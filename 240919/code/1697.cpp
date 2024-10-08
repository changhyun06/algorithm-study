#include <iostream>
#include <queue>

using namespace std;

int main()
{
  int a[1000000];
  cin.tie(NULL);
  ios::sync_with_stdio(false);
  queue<pair<int, int>> q;

  int n, k;

  cin >> n >> k;

  q.push({0, n});

  while (true)
  {
    pair<int, int> tmp = q.front();
    q.pop();
    int tmpcnt = tmp.first;
    int tmpnum = tmp.second;

    if (tmpnum == k)
    {
      cout << tmpcnt;
      break;
    }
    else
    { 
      if(tmpnum * 2 < k * 2 && a[tmpnum * 2] != 1){
        q.push({tmpcnt + 1, tmpnum * 2});
        a[tmpnum * 2] = 1;
      }
      if(a[tmpnum + 1] != 1){
        q.push({tmpcnt + 1, tmpnum + 1});
        a[tmpnum + 1] = 1;
      }
      if(tmpnum - 1 >=0 && a[tmpnum - 1] != 1){
        q.push({tmpcnt + 1, tmpnum - 1});
        a[tmpnum - 1] = 1;
      }
    }
  }
}