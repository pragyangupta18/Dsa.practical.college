#include <iostream>
#include <vector>
using namespace std;

const int MAX_CITIES = 50;

vector<string> cities;
vector <vector<int> >adj_mat;

int main()
{
    cout << "Enter the number of cities: ";
    int n;
    cin >> n;
    
    cities.resize(n);
    adj_mat.resize(n, vector<int>(n, 0));

    for (int i = 0; i < n; i++)
    {
        cout << "Enter city #" << i << " (Airport Code): ";
        cin >> cities[i];
    }
    
    cout << "\nYour cities are:\n";
    for (int i = 0; i < n; i++)
    {
        cout << "City #" << i << ": " << cities[i] << endl;
    }

    cout << "\nEnter 0 if there is no flight between cities.\n";
    for (int i = 0; i < n; i++)
    {
        for (int j = i + 1; j < n; j++)
        {
            cout << "Enter required fuel to reach " << cities[i] << " and " << cities[j] << ": ";
            cin >> adj_mat[i][j];
            adj_mat[j][i] = adj_mat[i][j];
        }
    }

    cout << "\nAdjacency Matrix:\n";
    for (int i = 0; i < n; i++)
    {
        cout << " \t" << cities[i] << "\t";
    }

    for (int i = 0; i < n; i++)
    {
        cout << endl << cities[i];
        for (int j = 0; j < n; j++)
        {
            cout << "\t" << adj_mat[i][j] << "\t";
        }
        cout << endl;
    }

    return 0;
}
