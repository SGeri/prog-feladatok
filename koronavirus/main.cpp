#include <iostream>
using namespace std;

int main()
{
    int max;
    cin >> max;

    int values_length;
    cin >> values_length;

    int values[values_length];
    for (int i = 0; i < values_length; i++)
    {
        cin >> values[i];
    }

    int max_infection = 0;
    int min_infection = 0;

    for (int i = 0; i < values_length; i++)
    {
        int starter_index = i;

        int local_max_infection = 0;
        int local_min_infection = 0;

        for (int i = 0; i < values_length; i++)
        {
            int left_offset_index = starter_index - i;
            int right_offset_index = starter_index + i;

            if (left_offset_index < 0)
                continue;
            if (right_offset_index > values_length - 1)
                continue;

            if (values[left_offset_index] <= values[left_offset_index + 1] - max)
            {
                local_max_infection++;
            }

            if (values[right_offset_index] <= values[right_offset_index - 1] - max)
            {
                local_min_infection++;
            }
        }

        if (local_max_infection > max_infection)
            max_infection = local_max_infection;

        if (local_min_infection > min_infection)
            min_infection = local_min_infection;
    }

    cout << max_infection << " " << min_infection << endl;

    return 0;
}