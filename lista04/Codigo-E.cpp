    #include <bits/stdc++.h>
    using namespace std;



    int main() {
            string s;
            cin >> s;

            bool tem_maiuscula = false;
            bool tem_minuscula = false;
            set<char> caracteres_vistos;
            bool todos_distintos = true;

            for (char c : s) {
                if (caracteres_vistos.count(c)) {
                    todos_distintos = false;
                }
                caracteres_vistos.insert(c);
                if (isupper(c)) tem_maiuscula = true;
                if (islower(c)) tem_minuscula = true;
            }

            if (tem_maiuscula && tem_minuscula && todos_distintos) {
                cout << "Yes" << endl;
            } else {
                cout << "No" << endl;
            }

            return 0;
        }
