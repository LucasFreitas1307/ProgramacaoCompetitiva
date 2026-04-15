    #include <bits/stdc++.h>
    using namespace std;

    int main() {
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);

        string n;
        cin >> n;

        int k = n.length();
        vector<int> r1, r2;
        long long soma = 0;

        for (int i = 0; i < k; i++) {
            int digito = n[i] - '0';
            soma += digito;
            if (digito % 3 == 1) r1.push_back(i);
            else if (digito % 3 == 2) r2.push_back(i);
        }

        int resto_total = soma % 3;
        if (resto_total == 0) {
            cout << 0 << endl;
        }
        else if (resto_total == 1) {
            if (r1.size() >= 1 && k > 1) {
                cout << 1 << endl;
            }
            else if (r2.size() >= 2 && k > 2) {
                cout << 2 << endl;
            }
            else {
                cout << -1 << endl;
            }
        }
        else if (resto_total == 2) {
            if (r2.size() >= 1 && k > 1) {
                cout << 1 << endl;
            }
            else if (r1.size() >= 2 && k > 2) {
                cout << 2 << endl;
            }
            else {
                cout << -1 << endl;
            }
        }
        return 0;
        }
