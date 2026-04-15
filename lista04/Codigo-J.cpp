#include <bits/stdc++.h>
using namespace std;
#define MAX 30

typedef long long int ll;

vector<int> A,B;
ll ans = 20'000'000'000ll;
int maca[MAX],n;

void gen(int id){
    if(id == n){
        ll sumA = 0, sumB = 0;
        for(int i=0; i<A.size(); i++) sumA += A[i];
        for(int i=0; i<B.size(); i++) sumB += B[i];
        ans = min(ans, abs(sumA-sumB));
    }else{
        A.push_back(maca[id]);
        gen(id+1);
        A.pop_back();

        B.push_back(maca[id]);
        gen(id+1);
        B.pop_back();
    }
}

int main(){
    ios::sync_with_stdio(NULL);
    cin.tie(NULL);
    cin >> n;
    for(int i=0; i<n; i++) cin >> maca[i];
    gen(0);
    cout << ans << '\n';
}
