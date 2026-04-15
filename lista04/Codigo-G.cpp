#include <bits/stdc++.h>
using namespace std;

bool diferente(const string &a, const string &b, int m) {
    int diff = 0;
    for (int i = 0; i < m; i++) {
        if (a[i] != b[i]) diff++;
    }
    return diff == 1;
}

int main() {
    int n, m;
    if (!(cin >> n >> m)) return 0;

    vector<string> s(n);
    vector<int> p(n);
    for (int i = 0; i < n; i++) {
        cin >> s[i];
        p[i] = i;
    }

    sort(p.begin(), p.end());

    do {
        bool possivel = true;
        for (int i = 0; i < n - 1; i++) {
            if (!diferente(s[p[i]], s[p[i+1]], m)) {
                possivel = false;
                break;
            }
        }

        if (possivel) {
            cout << "Yes" << endl;
            return 0;
        }
    } while (next_permutation(p.begin(), p.end()));

    cout << "No" << endl;
    return 0;
}
