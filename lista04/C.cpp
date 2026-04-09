#include <bits/stdc++.h>
using namespace std;

void SequenciaGerada(int n) {
    if (n == 1) {
        cout << 1;
        return;
    }

    SequenciaGerada(n - 1); 
    cout << " " << n << " ";
    SequenciaGerada(n - 1); 

}

int main() {
int n;
if (!(cin >> n))
    return 0;

    SequenciaGerada(n);
    cout << endl;
    return 0;

}
