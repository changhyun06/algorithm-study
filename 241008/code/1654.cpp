#include <iostream>
#include <algorithm>

using namespace std;

long long a[10000];
long  k, n;
long  maxlen = 0;

void test(long left, long right) {
  if(right - left <= 1){
    return;
  }

  int cnt = 0;
  int tmplen = (left + right) / 2;
  

  for(int i=0; i<k; i++){
    cnt += a[i] / tmplen;
  }

  if(cnt < n){
    return test(left, tmplen);
  }

  if(cnt >= n){
    maxlen = tmplen;
    return test(tmplen, right);
  }
}

int main()
{
  cin >> k >> n;

  for (int i = 0; i < k; i++)
  {
    cin >> a[i];
  }

  sort(a, a + k);

  test(0, a[k-1] + 1);

  cout<<maxlen;
  
}