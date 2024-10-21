#include <iostream>
using namespace std;
void towerOfHanoi(int n, char a, char b, char c) {
    if (n == 1) {
        cout << "Move disk 1 from " << a << " to " << c << endl;
        return;
    }
    towerOfHanoi(n - 1, a, c, b);
    cout << "Move disk " << n << " from " << a << " to " << c <<endl;
    towerOfHanoi(n - 1, b, a, c);
}

int main() {
    int n;
    cout << "Enter the number of disks: ";
    cin >> n;
    cout << "Tower of Hanoi solution:" <<endl;
    towerOfHanoi(n, 'A', 'B', 'C');
    cout<<"23DCS089_Samarth Patel";
    return 0;
}