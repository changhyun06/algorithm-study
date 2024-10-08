#include <iostream>
#include <queue>

using namespace std;

int main()
{
  cin.tie(0);
  ios::sync_with_stdio(false);
  int n, m;
  int a[1000][1000];
  int vis[1000][1000] = {
      0,
  };
  queue<pair<int, int>> q;
  int x[4] = {-1, 0, 1, 0};
  int y[4] = {0, -1, 0, 1};
  int day = 0;

  cin >> m >> n;

  for (int i = 0; i < n; i++)
  {
    for (int j = 0; j < m; j++)
    {
      cin >> a[i][j];
      if (a[i][j] == 1)
      {
        q.push({i, j});
      }
    }
  }

  while (!q.empty())
  {
    pair<int, int> tmp = q.front();
    q.pop();
    for (int k = 0; k < 4; k++)
    {
      int tmpx = tmp.first + x[k];
      int tmpy = tmp.second + y[k];
      int cnt = vis[tmp.first][tmp.second];

      if (tmpx < 0 || tmpy < 0 || tmpx > n - 1 || tmpy > m - 1)
      {
        continue;
      }

      if (vis[tmpx][tmpy] <= cnt + 1 && vis[tmpx][tmpy] != 0 || a[tmpx][tmpy] == 1 || a[tmpx][tmpy] == -1)
      {
        continue;
      }

      q.push({tmpx, tmpy});
      vis[tmpx][tmpy] = cnt + 1;
    }
  }

  for (int i = 0; i < n; i++)
  {
    for (int j = 0; j < m; j++)
    {
      if (a[i][j] == 0 && vis[i][j] == 0)
      {
        cout << -1;
        return 0;
      }
      if (day < vis[i][j])
      {
        day = vis[i][j];
      }
    }
  }

  cout << day;
}