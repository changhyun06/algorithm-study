#include <iostream>
#include <queue>

using namespace std;

int main()
{
  cin.tie(NULL);
  ios::sync_with_stdio(false);
  int t, n;
  int inx, iny;
  queue<pair<int, pair<int, int>>> q;
  int x[8] = {-2, -1, 2, 1, -2, -1, 2, 1};
  int y[8] = {-1, -2, 1, 2, 1, 2, -1, -2};
  int ocnt = 0;
  bool finish = false;

  cin >> t;

  for (int i = 0; i < t; i++)
  {
    ocnt = 0;
    finish = false;
    bool vis[300][300] = {
        false,
    };
    int a[300][300] = {
        0,
    };
    cin >> n;
    cin >> inx >> iny;
    a[inx][iny] = 1;
    vis[inx][iny] = true;
    q.push({0, {inx, iny}});
    cin >> inx >> iny;
    a[inx][iny] = 1;

    while (!q.empty())
    {
      pair<int, pair<int, int>> tmp = q.front();
      q.pop();

      for (int i = 0; i < 8; i++)
      {
        int tmpx = tmp.second.first + x[i];
        int tmpy = tmp.second.second + y[i];
        int tmpcnt = tmp.first;


        if (tmpx < 0 || tmpy < 0 || tmpx > n - 1 || tmpy > n - 1)
        {
          continue;
        }

        if (vis[tmpx][tmpy])
        {
          continue;
        }

        if (a[tmpx][tmpy] == 1)
        {
          ocnt = tmpcnt + 1;
          finish = true;
          break;
        }

        q.push({tmpcnt + 1, {tmpx, tmpy}});
        vis[tmpx][tmpy] = true;
      }
      if(finish){
        break;
      }
    }

    cout << ocnt << "\n";

    while (!q.empty()) q.pop();
  }
}