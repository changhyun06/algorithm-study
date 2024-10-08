#include <iostream>
#include <queue>

using namespace std;

int main()
{
  ios::sync_with_stdio(false);
  cin.tie(NULL);

  int n, m;
  string b[1000];
  int a[1000][1000] = {
      0,
  };
  int cnt = 0;
  queue<pair<int, pair<int, int>>> q;
  queue<pair<int, int>> q1;
  int x[4] = {-1, 0, 1, 0};
  int y[4] = {0, -1, 0, 1};
  int min = 1000000;

  cin >> n >> m;

  for (int i = 0; i < n; i++)
  {
    cin >> b[i];
  }

  for (int i = 0; i < n; i++)
  {
    for (int j = 0; j < m; j++)
    {
      a[i][j] = b[i][j] - 48;
    }
  }

  q.push({1, {0, 0}});

  for (int i = 0; i < n; i++)
  {
    for (int j = 0; j < m; j++)
    {
      bool vis1[1000][1000] = {
          false,
      };

      if (a[i][j] != 1 || vis1[i][j])
      {
        continue;
      }

      q1.push({i, j});

      while (!q1.empty())
      {
        pair<int, int> tmp = q1.front();
        q1.pop();
        int cnt1 = 0;
        int tmpxx = tmp.first;
        int tmpyy = tmp.second;

        for (int k = 0; k < 4; k++)
        {
          int tmpx = tmpxx + x[k];
          int tmpy = tmpyy + y[k];
          int tmpcnt = tmp.first;

          if (tmpx < 0 || tmpy < 0 || tmpx > n - 1 || tmpy > m - 1)
          {
            continue;
          }

          if (vis1[tmpx][tmpy] || a[tmpx][tmpy] != 1)
          {
            continue;
          }

          q1.push({tmpx, tmpy});
          vis1[tmpx][tmpy] = true;
          cnt1++;
        }

        if (cnt1 == 1)
        {
          a[tmpxx][tmpyy] = 0;
        }
      }
    }
  }

  bool vis[1000][1000] = {
      false,
  };

  while (!q.empty())
  {
    pair<int, pair<int, int>> tmp = q.front();
    q.pop();

    if (tmp.second.first == n - 1 && tmp.second.second == m - 1)
    {
      cnt++;
      if (min > tmp.first)
      {
        min = tmp.first;
      }
      break;
    }

    for (int k = 0; k < 4; k++)
    {
      int tmpx = tmp.second.first + x[k];
      int tmpy = tmp.second.second + y[k];
      int tmpcnt = tmp.first;

      if (tmpx < 0 || tmpy < 0 || tmpx > n - 1 || tmpy > m - 1)
      {
        continue;
      }

      if (vis[tmpx][tmpy] || a[tmpx][tmpy] != 0)
      {
        continue;
      }

      q.push({tmpcnt + 1, {tmpx, tmpy}});
      vis[tmpx][tmpy] = true;
    }
  }

  // for (int i = 0; i < n; i++)
  // {
  //   for (int j = 0; j < m; j++)
  //   {
  //     bool vis[1000][1000] = {
  //         false,
  //     };

  //     q.push({1, {0, 0}});

  //     if (i == 0 && j == 0)
  //     {

  //     }
  //     else if (a[i][j] == 1)
  //     {
  //       a[i][j] = 0;
  //       while (!q.empty())
  //       {
  //         pair<int, pair<int, int>> tmp = q.front();
  //         q.pop();

  //         if (tmp.second.first == n - 1 && tmp.second.second == m - 1)
  //         {
  //           cnt++;
  //           if (min > tmp.first)
  //           {
  //             min = tmp.first;
  //           }
  //           break;
  //         }

  //         for (int k = 0; k < 4; k++)
  //         {
  //           int tmpx = tmp.second.first + x[k];
  //           int tmpy = tmp.second.second + y[k];
  //           int tmpcnt = tmp.first;

  //           if (tmpx < 0 || tmpy < 0 || tmpx > n - 1 || tmpy > m - 1)
  //           {
  //             continue;
  //           }

  //           if (vis[tmpx][tmpy] || a[tmpx][tmpy] != 0)
  //           {
  //             continue;
  //           }

  //           q.push({tmpcnt + 1, {tmpx, tmpy}});
  //           vis[tmpx][tmpy] = true;
  //         }
  //       }
  //       a[i][j] = 1;
  //     }
  //   }
  // }

  if (cnt == 0)
  {
    cout << -1;
  }
  else
  {
    cout << min;
  }
}