#include <iostream>
using namespace std;

int main()
{
    int v;
    cin >> v;

    int values[v];
    for (int i = 0; i < v; i++)
    {
        cin >> values[i];
    }

    int times = values[0] < 0 ? 1 : 0;

    for (int i = 1; i < v; i++)
    {
        if (values[i] < 0 && values[i - 1] >= 0)
        {
            times++;
        }
    }

    cout << times << endl;

    return 0;
}