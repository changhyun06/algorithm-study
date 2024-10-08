#include <iostream>
#include <queue>

using namespace std;

int main()
{
  cin.tie(NULL);
  ios::sync_with_stdio(false);
  int a[100][100][100] = {
      0,
  };
  int vis[100][100][100] = {
      0,
  };
  int n, m, h;
  queue<pair<int, pair<int, int>>> q;
  int x[5] = {-1, 0, 1, 0, 0};
  int y[5] = {0, -1, 0, 1, 0};
  int z[3] = {-1, 0, 1};    
  int lcnt = 0;
  int maxcnt = 0;

  cin >> m >> n >> h;

  for (int i = 0; i < h; i++)
  {
    for (int j = 0; j < n; j++)
    {
      for (int k = 0; k < m; k++)
      {
        cin >> a[i][j][k];
        if (a[i][j][k] == 1)
        {
          q.push({i, {j, k}});
        }
      }
    }
  }

  while (!q.empty())
  {
    pair<int, pair<int, int>> tmp = q.front();
    q.pop();

    for (int i = 0; i < 3; i++)
    {
      for (int j = 0; j < 5; j++)
      {
          int tmpx = tmp.second.first + x[j];
          int tmpy = tmp.second.second + y[j];
          int tmpz = tmp.first;
          if(j == 4){
            tmpz += z[i];
          }

          if (tmpx < 0 || tmpy < 0 || tmpz < 0 || tmpx > n - 1 || tmpy > m - 1 || tmpz > h - 1)
          {
            continue;
            ;
          }

          int cnt = vis[tmp.first][tmp.second.first][tmp.second.second];
          int tmpcnt = vis[tmpz][tmpx][tmpy];

          if (tmpcnt <= cnt + 1 && tmpcnt != 0 || a[tmpz][tmpx][tmpy] == 1 || a[tmpz][tmpx][tmpy] == -1)
          {
            continue;
          }

          vis[tmpz][tmpx][tmpy] = cnt + 1;
          q.push({tmpz, {tmpx, tmpy}});
      }
    }
  }

  for (int i = 0; i < h; i++)
  {
    for (int j = 0; j < n; j++)
    {
      for (int k = 0; k < m; k++)
      {
        if (vis[i][j][k] == 0 && a[i][j][k] == 0)
        {
          cout << -1;
          return 0;
          ;
        }

        if (maxcnt < vis[i][j][k])
        {
          maxcnt = vis[i][j][k];
        }
      }
    }
  }

  cout << maxcnt;
}