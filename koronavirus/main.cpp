#include <iostream>
using namespace std;

// wip todo:
// ha egy szekció megvan, akkor az összes eleme skipelhető
// a be1-nél valami el van baszva, a 2-es indexnél 4-en ír valamiért (valszeg a végével nem jó valami)

int main()
{
    // read data
    int values_length;
    cin >> values_length;

    int max;
    cin >> max;

    int values[values_length];
    for (int i = 0; i < values_length; i++)
    {
        cin >> values[i];
    }

    // declare logic variables
    int max_infection = -1;
    int min_infection = -1;

    // loop through values
    // to find the max and min infection amount
    for (int starter_index = 0; starter_index < values_length; starter_index++)
    {
        int local_infection = 1;

        // only have to go in the right direction
        // because the left direction is already checked by the fact that
        // there are sections where the infection amount is the same
        for (int i = 0; i < values_length - starter_index; i++)
        {
            if (values[starter_index + i] + max >= values[starter_index + i + 1])
            {
                local_infection++;
            }
            else
            {
                break;
            }
        }

        // compare local infection
        if (local_infection > max_infection || max_infection == -1)
        {
            max_infection = local_infection;
        }

        if (local_infection < min_infection || min_infection == -1)
        {
            min_infection = local_infection;
        }

        // for testing purposes
        // cout << "starter_index: " << starter_index << " starter_value: " << values[starter_index] << " local_infection: " << local_infection << endl;
    }

    cout << max_infection << " " << min_infection << endl;

    return 0;
}