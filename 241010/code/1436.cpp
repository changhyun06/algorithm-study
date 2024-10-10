#include <iostream>
#include <string>

using namespace std;

int main() {
  int n;
  int cnt=0;
  int result = 666;

  cin>>n;


  while(true){
    string tmp = to_string(result);

    if(tmp.find("666") != string::npos){
      cnt++;
    }

    if(cnt == n) {
      break;
    }

    result++;
  
  }

  cout<<result;

}