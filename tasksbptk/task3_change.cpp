#include <iostream>
#include <limits>
#include <algorithm>
#include <vector>
#include <string>

using namespace std;

static int GetInt()
{
    int result = 0;

    do
    {
        cout << "Please, input change: ";
        cin >> result;
        if ( cin.fail() )
        {
            cout << "Wrong input, try again!" << endl;
            cin.clear();
            cin.ignore(numeric_limits<int>::max(), '\n');
        }
        else if ( result < 0 )
        {
            cout << "Negative value forbidden!" << endl;
            continue;
        }
        else
        {
            break;
        }
    } while ( true );

    return result;
}

int main()
{
    const int coinsCoint = 5;
    const int COINS[coinsCoint] = { 100, 25, 10, 5, 1 };
    int i = 0;
    int change = GetInt();

    cout << "Your change is: ";
    while ( change > 0 )
    {
        if ( change % COINS[i] != change )
        {
            change -= COINS[i];
            cout << COINS[i] << ' ';
        }
        else
        {
            i = (i + 1) % coinsCoint;
        }
    }

    cout << endl;

    cout << "Program endpoint." << endl;
    system("pause");

    return 0;
}
