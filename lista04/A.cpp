#include <bits/stdc++.h>
using namespace std;

int main(){

  long long a, b, c, k;

  if(!(cin >> a >> b >> c >> k))
    return 0;

  long long soma;

  soma = 0;


  if(k <= a){
    soma = k;
    k=0;
    
  }
  else {
    soma = a;
    k -= a;
  }

  if(k > 0) {
    if(k <= b) {
      k=0;
    }
    else{
      k -= b;
    }
  }
  if(k > 0) {
    soma -=k;
  }
  cout << soma << endl;
  return 0;
}
