#include <bits/stdc++.h>
using namespace std;

int cnt = 0;
vector<pair<int,int>> movs;
void move(int p1,int p2){
    movs.push_back(make_pair(p1,p2));
    cnt++;
}
void hanoi(int n,int init, int dst, int aux){
    if(n == 1) move(init,dst);
    else{
        hanoi(n-1,init,aux,dst);
        move(init,dst);
        hanoi(n-1,aux,dst,init);
    }
}

int main(){
    ios::sync_with_stdio(NULL);
    cin.tie(NULL);
    int n; 
    cin >> n;
    hanoi(n,1,3,2);
    cout << cnt << '\n';
    for(int i=0; i<movs.size(); i++){
        cout << movs[i].first << ' ' << movs[i].second << '\n';
    }
    return 0;
}
