#include <iostream>
#include <queue>
#include <cstring>

using namespace std;

int main()
{
  cin.tie(NULL);
  ios::sync_with_stdio(false);

  int t;
  int w, h;
  int x[4] = {-1, 0, 1, 0};
  int y[4] = {0, -1, 0, 1};

  cin >> t;

  for (int i = 0; i < t; i++)
  {
    string s[1000];
    pair<char, int> vis[1000][1000];
    queue<pair<int, pair<int, int>>> q;
    int min = 10000000;
    memset(vis, 0, sizeof(vis));
    
    cin >> w >> h;

    for (int j = 0; j < h; j++)
    {
      cin >> s[j];
    }

    for (int j = 0; j < h; j++)
    {
      for (int k = 0; k < w; k++)
      {
        if (s[j][k] == '@' || s[j][k] == '*')
        {
          q.push({1, {j, k}});
          vis[j][k] = {s[j][k], 1};
        }
      }
    }

    while (!q.empty())
    {
      pair<int, pair<int, int>> tmp = q.front();
      q.pop();
      int tmptime = tmp.first;

      for (int j = 0; j < 4; j++)
      {
        int tmpx = tmp.second.first + x[j];
        int tmpy = tmp.second.second + y[j];

        if (tmpx < 0 || tmpy < 0 || tmpx > h - 1 || tmpy > w - 1)
        {
          continue;
        }

        if (s[tmpx][tmpy] == '#')
        {
          continue;
        }

        if (s[tmp.second.first][tmp.second.second] == '*' && vis[tmpx][tmpy].first == '*' && vis[tmpx][tmpy].second < tmptime + 1 || vis[tmpx][tmpy].first == '@' && vis[tmpx][tmpy].second < tmptime + 1)
        {
          continue;
        }

        if (s[tmp.second.first][tmp.second.second] == '@' && vis[tmpx][tmpy].first == '@' || vis[tmpx][tmpy].first == '*' && vis[tmpx][tmpy].second <= tmptime + 1)
        {
          continue;
        }

        q.push({tmptime + 1, {tmpx, tmpy}});
        vis[tmpx][tmpy] = {vis[tmp.second.first][tmp.second.second].first, tmptime + 1};
      }
    }

    // for (int j = 0; j < h; j++)
    // {
    //   for (int k = 0; k < w; k++)
    //   {
    //     cout << vis[j][k].first << "," << vis[j][k].second;
    //   }
    //   cout << '\n';
    // }

    for (int j = 0; j < h; j++)
    {
      for (int k = 0; k < w; k++)
      {
        if (j == h - 1 || j == 0 || k == w - 1 || k == 0)
        {
          if (vis[j][k].first == '@' && vis[j][k].second < min)
          {
            min = vis[j][k].second;
          }
        }
      }
    }

    if (min < 10000000)
    {
      cout << min << "\n";
    }
    else
    {
      cout << "IMPOSSIBLE" << "\n";
    }
  }
}