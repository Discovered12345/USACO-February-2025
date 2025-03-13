#include <bits/stdc++.h>
#define ll long long
#define pii pair<int, int>

using namespace std;

const int MAX_N = 2e5 + 1; 
int array_size, max_value, FjFavCows[MAX_N], frequency_count[MAX_N], prefix_sum[MAX_N], cumulative_sum[MAX_N]; 

int main()
{
    ios::sync_with_stdio(false); 
    cin.tie(nullptr); 
    
    cin >> array_size; 
    
    for (int i = 0; i < array_size; i++) { 
        cin >> FjFavCows[i]; 
    }
    
    max_value = array_size;
    
    for (int i = 0; i < array_size; i++) { 
        frequency_count[FjFavCows[i]]++; 
    }
    
    for (int i = 0; i <= max_value; i++) {
        if (frequency_count[i] > 0) { 
            prefix_sum[i] = 1; 
        }
    }
    
    for (int i = 1; i <= max_value + 1; i++) { 
        cumulative_sum[i] = cumulative_sum[i - 1] + (prefix_sum[i - 1] ? 1 : 0); 
    }

    for (int mex_value = 0; mex_value <= max_value; mex_value++) {
        int min_operations = mex_value - cumulative_sum[mex_value];
        int frequency = frequency_count[mex_value];
        cout << max(min_operations, frequency) << endl; 
    }
    
    return 0;
}