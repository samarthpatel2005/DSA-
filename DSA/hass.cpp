#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;

int main()
{
    int arr[20];
    srand(time(0));
    for (int i = 0; i < 20; i++)
    {
        arr[i] = -1;
    }
    int count = 0;
    for (count = 0; count < 15; count++)
    {
        int val = 300000 + rand() % 900000;
        int key = (val % 18) + 2;
        while (arr[key] != -1)
        {
            key = (key + 1) % 20;
        }
        arr[key] = val;
    }
    for (int i = 0; i < 20; i++)
    {
        cout << "Index " << i << ": " << arr[i] << endl;
    }
    cout << "23DCS089_Samarth";
    return 0;
}