#include <bits/stdc++.h>
using namespace std;

void towOfHanoi(int n, int t1, int t2, int t3)
{
    if(n == 0) return;

    towOfHanoi(n-1, t1, t3, t2);
    cout<< n << "  ["<<t1<<" ->  "<<t2<<"]"<< endl;
    towOfHanoi(n-1, t3, t2, t1);
}

int main()
{
    int n;
    cout << "Number of disks: ";
    cin >> n;
    towOfHanoi(n, 1, 2, 3);
}
