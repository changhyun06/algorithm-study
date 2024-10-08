#include <iostream>
#include <queue>

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(NULL);

  string a[100];
  int n;
  bool vis[100][100] = {false,};
  bool vis2[100][100] = {false,};
  queue<pair<int,int>> q;
  queue<pair<int,int>> q2;
  int cnt = 0;
  int cnt2 = 0;
  int x[4] = {-1,0,1,0};
  int y[4] = {0,-1,0,1};

  cin>>n;

  for(int i=0; i<n; i++){
    cin>>a[i];
  }

  for(int i=0; i<n; i++){
    for(int j=0; j<n; j++){

      if(vis[i][j]){
        continue;
      }

      q.push({i,j});
      cnt++;

      if(a[i][j] == 'R'){
        while(!q.empty()){
          pair<int,int> tmp = q.front();
          q.pop();

          for(int k=0; k<4; k++){
            int tmpx = tmp.first + x[k];
            int tmpy = tmp.second + y[k];

            if(tmpx < 0 || tmpy < 0 || tmpx > n-1 || tmpy > n-1){
              continue;
            }

            if(a[tmpx][tmpy] != 'R' || vis[tmpx][tmpy]){
              continue;
            }

            q.push({tmpx,tmpy});
            vis[tmpx][tmpy] = true;
          }
        }
      }else if(a[i][j] == 'G'){
        while(!q.empty()){
          pair<int,int> tmp = q.front();
          q.pop();

          for(int k=0; k<4; k++){
            int tmpx = tmp.first + x[k];
            int tmpy = tmp.second + y[k];

            if(tmpx < 0 || tmpy < 0 || tmpx > n-1 || tmpy > n-1){
              continue;
            }

            if(a[tmpx][tmpy] != 'G' || vis[tmpx][tmpy]){
              continue;
            }

            q.push({tmpx,tmpy});
            vis[tmpx][tmpy] = true;
          }
        }
      }else{
        while(!q.empty()){
          pair<int,int> tmp = q.front();
          q.pop();

          for(int k=0; k<4; k++){
            int tmpx = tmp.first + x[k];
            int tmpy = tmp.second + y[k];

            if(tmpx < 0 || tmpy < 0 || tmpx > n-1 || tmpy > n-1){
              continue;
            }

            if(a[tmpx][tmpy] != 'B' || vis[tmpx][tmpy]){
              continue;
            }

            q.push({tmpx,tmpy});
            vis[tmpx][tmpy] = true;
          }
        }
      }
    }
  }

  for(int i=0; i<n; i++){
    for(int j=0; j<n; j++){

      if(vis2[i][j]){
        continue;
      }

      q2.push({i,j});
      cnt2++;

      if(a[i][j] != 'B'){
        while(!q2.empty()){
          pair<int,int> tmp = q2.front();
          q2.pop();

          for(int k=0; k<4; k++){
            int tmpx = tmp.first + x[k];
            int tmpy = tmp.second + y[k];

            if(tmpx < 0 || tmpy < 0 || tmpx > n-1 || tmpy > n-1){
              continue;
            }

            if(a[tmpx][tmpy] == 'B' || vis2[tmpx][tmpy]){
              continue;
            }

            q2.push({tmpx,tmpy});
            vis2[tmpx][tmpy] = true;
          }
        }
      } else{
        while(!q2.empty()){
          pair<int,int> tmp = q2.front();
          q2.pop();

          for(int k=0; k<4; k++){
            int tmpx = tmp.first + x[k];
            int tmpy = tmp.second + y[k];

            if(tmpx < 0 || tmpy < 0 || tmpx > n-1 || tmpy > n-1){
              continue;
            }

            if(a[tmpx][tmpy] != 'B' || vis2[tmpx][tmpy]){
              continue;
            }

            q2.push({tmpx,tmpy});
            vis2[tmpx][tmpy] = true;
          }
        }
      }
    }
  }

  cout<<cnt<<' '<<cnt2;
}