#include <iostream>
#include <algorithm>
#include <string>

#include <cctype>

using namespace std;

static int GetInt()
{
    int result = 0;

    do
    {
        cout << "Please, input iteration count: ";
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
        else if ( result == 0 )
        {
            cout << "Iteration value must be greater than 0!" << endl;
            continue;
        }
        else
        {
            break;
        }
    } while ( true );

    return result;
}

static string GetInitialSequence()
{
    string result = "";

    do
    {
        cout << "Please, input initial sequence of digits. ForExample, enter 1: ";
        cin >> result;

        string::iterator it = find_if(result.begin(), result.end(), [](int a) -> bool { return !isdigit(a); });
        if ( it != result.end() )
        {
            cout << "Wrong input sequence! Only digits allowed! Retry..." << endl;
            continue;
        }

        if ( result.empty() )
        {
            cout << "Wrong input sequence! Sequence is empty! Retry..." << endl;
            continue;
        }

        break;

    } while ( true );

    return result;
}

static string GenerateNewSequence(const string &sequence)
{
    string result = "";
    char currentDigit = 0;
    int count = 0;

    currentDigit = sequence[0];
    count = 1;

    for ( string::size_type i = 1; i < sequence.length(); ++i )
    {
        if ( currentDigit == sequence[i] )
        {
            ++count;
        }
        else
        {
            result += to_string(count);
            result += currentDigit;

            currentDigit = sequence[i];
            count = 1;
        }
    }

    result += to_string(count);
    result += currentDigit;

    return result;
}

int main()
{
    cout << "Look-And-Say sequence." << endl;

    int iterationCount = GetInt();
    string sequence = GetInitialSequence();

    for ( int i = 0; i < iterationCount; ++i )
    {
        cout << sequence << endl;
        sequence = GenerateNewSequence(sequence);
    }

    cout << "Program endpoint." << endl;
    system("pause");

    return 0;
}
