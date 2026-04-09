#include <bits/stdc++.h>
using namespace std;

int main() {
    string t, u;

    if (!(cin >> t >> u))
        return 0;

    int n = t.length();
    int m = u.length();
    
    for (int i = 0; i <= n - m; i++) {
        bool achei = true;
        
        for (int j = 0; j < m; j++) {
            if (t[i + j] != '?' && t[i + j] != u[j]) {
                achei = false;
                break;
            }
        }
        
        if (achei) {
            cout << "Yes" << endl;
            return 0;
        }
    }
    
    cout << "No" << endl;
    return 0;
}
