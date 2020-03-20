#include <iostream>
#include <algorithm>
#define UPPERBOUND 1000000
#define LOWERBOUND 0
using namespace std;

int main(void)
{
    int start, end;
    cin >> start >> end;

    if (start > UPPERBOUND || start < LOWERBOUND || end > UPPERBOUND || end < LOWERBOUND)
    {
        cout << "Invalid input(out of bounds)" << endl;
        return -1;
    }

    int counter = 0;
    int result;
    int arr[end - start + 1];
    int arr_index = 0;

    for (int i = start; i <= end; i++)
    {
        result = i;
        counter++;
        while (result != 1)
        {
            if (result % 2 == 0)
            {
                result /= 2;
                counter++;
            }
            else
            {
                result *= 3;
                result++;
                counter++;
            }
        }
        arr[arr_index] = counter;
        arr_index++;
        counter = 0;
    }
    sort(arr, arr + arr_index);
    cout << start << " " << end << " " << arr[arr_index - 1] << endl;
    return 0;
}