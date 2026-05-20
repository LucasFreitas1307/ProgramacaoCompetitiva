#include <iostream>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    cin >> n;

    long long soma_total = 0;

    for (int i = 0; i < n; i++) {
        long long a, b;
        cin >> a >> b;
        long long soma_b = (b * (b + 1)) / 2;
        long long soma_a_menos_1 = ((a - 1) * a) / 2;
        soma_total += (soma_b - soma_a_menos_1);
    }
    cout << soma_total << "\n";

    return 0;
}
