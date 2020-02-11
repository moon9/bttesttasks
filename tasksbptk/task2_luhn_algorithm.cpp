#include <iostream>
#include <string>
#include <algorithm>

#include <cctype>

using namespace std;

static string GetId()
{
    string result = "";

    do
    {
        cout << "Please, input ID for \"Luhn\" check. ForExample, enter \"4539 1488 0343 6467\": ";
        getline(cin, result);

        string::iterator it = find_if(result.begin(), result.end(), [](int a) -> bool { return !isdigit(a) && a != ' '; });
        if ( it != result.end() )
        {
            cout << "Wrong input ID! Only digits and spaces allowed! Retry..." << endl;
            continue;
        }

        if ( result.empty() || result.length() == 1 )
        {
            cout << "Wrong input ID! ID is empty or it length equal to 1! Retry..." << endl;
            continue;
        }

        break;

    } while ( true );

    result.erase(std::remove(result.begin(), result.end(), ' '), result.end());

    return result;
}

static void MultiplyEven(string &id)
{
    for ( string::size_type i = 0; i < id.length(); ++i )
    {
        if ( (i % 2) == 0 )
        {
            int a = (id[i] - '0') * 2;
            if ( a > 9 )
            {
                a -= 9;
            }

            id[i] = a + '0';
        }
    }
}

static unsigned int GetSumFromId(const string &id)
{
    unsigned int result = 0;

    for ( string::size_type i = 0; i < id.length(); ++i )
    {
        result += id[i] - '0';
    }

    return result;
}

static bool LuhnCheck(unsigned int sum)
{
    return (sum % 10) == 0;
}

int main()
{
    cout << "Luhn algorithm." << endl;

    string id = GetId();
    MultiplyEven(id);
    unsigned int idSum = GetSumFromId(id);
    if ( LuhnCheck(idSum) )
    {
        cout << "ID is valid!" << endl;
    }
    else
    {
        cout << "ID is invalid!" << endl;
    }

    cout << "Program endpoint." << endl;
    system("pause");

    return 0;
}
