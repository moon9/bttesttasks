#include <iostream>
#include <limits>

#include <cmath>

using namespace std;

static void GetPoints(int *array, int length)
{
    bool isEnd = false;

    do
    {
        cout << "Please, input coordinates of 2 queens in format x1 y1 x2 y2 (range 0-7 for both axes): ";
        for ( int i = 0; i < length; ++i )
        {
            cin >> array[i];
            if ( cin.fail() )
            {
                cout << "Wrong input, try again!" << endl;
                cin.clear();
                cin.ignore(numeric_limits<int>::max(), '\n');
                isEnd = false;
                break;
            }
            else if ( array[i] < 0 )
            {
                cout << "Wrong input, negative value!" << endl;
                cin.clear();
                cin.ignore(numeric_limits<int>::max(), '\n');
                isEnd = false;
                break;
            }
            else if ( array[i] > 7 )
            {
                cout << "Wrong input, value must in range 0-7!" << endl;
                cin.clear();
                cin.ignore(numeric_limits<int>::max(), '\n');
                isEnd = false;
                break;
            }
            else
            {
                isEnd = true;
            }
        }
    } while ( !isEnd );
}

int main()
{
    const int pointsCount = 4;
    int queensPoints[pointsCount];
    bool attackAvailable = false;

    cout << "Check Queens can attack" << endl;

    GetPoints(queensPoints, pointsCount);

    // Check by lines
    if ( queensPoints[0] == queensPoints[2] ||
         queensPoints[1] == queensPoints[3] )
    {
        attackAvailable = true;
    }
    // Check by diagonale
    else
    {
        int x = abs(queensPoints[0] - queensPoints[2]);
        int y = abs(queensPoints[1] - queensPoints[3]);
        if ( x == y )
        {
            attackAvailable = true;
        }
    }

    if ( attackAvailable )
    {
        cout << "Queens have collision" << endl;
    }
    else
    {
        cout << "Queens haven't collision" << endl;
    }

    cout << "Program endpoint." << endl;
    system("pause");

    return 0;
}