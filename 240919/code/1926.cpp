#include <iostream>
#include <queue>
#include <algorithm>

using namespace std;

int main()
{
  int n, m;
  int cnt = 0;
  int area = 0, maxarea = 0;
  int a[500][500];
  int x[4] = {0, -1, 0, 1};
  int y[4] = {-1, 0, 1, 0};
  queue<pair<int, int>> q;
  bool vis[500][500];

  cin >> n >> m;

  //입력
  for (int i = 0; i < n; i++)
  {
    for (int j = 0; j < m; j++)
    {
      cin >> a[i][j];
    }
  }

  //탐색할수 있는 그림을 찾기
  for (int i = 0; i < n; i++)
  {
    for (int j = 0; j < m; j++)
    {
      //탐색을 못하면 넘어가기
      if(a[i][j] != 1 || vis[i][j]){
        continue;
      }
      q.push({i,j});
      vis[i][j] = true;
      cnt++;
      area = 0;
      //시작점부터 넓이 측정
      while (!q.empty())
      {
        pair<int, int> tmp = q.front();
        q.pop();
        area++;
        //탐색
        for (int k = 0; k < 4; k++)
        {
          int tmpx = tmp.first + x[k];
          int tmpy = tmp.second + y[k];

          //범위를 벗어나면 continue
          if(tmpx < 0 || tmpx > n-1 || tmpy < 0 || tmpy > m-1){
            continue;
          }

          //이미 방문햇으면 continue
          if(vis[tmpx][tmpy] || a[tmpx][tmpy] != 1){
            continue;
          }

          q.push({tmpx,tmpy});
          vis[tmpx][tmpy] = true;
        }
      }

      if(area > maxarea){
        maxarea = area;
      }
    }
  }

  cout << cnt << '\n'
       << maxarea;
}