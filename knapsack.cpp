#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Item{
    // The value of the item, weight of the item and the original index of the item.
    int value, weight, index;

    public:
    // Constructor.
    Item(int value, int weight, int index){ this->value = value; this->weight = weight; this->index = index; }

    // Getters.
    const int getValue() const { return value; }
    const int getWeight() const { return weight; }    
    const int getIndex() const { return index; }     

    // Operators.
    bool operator<(const Item& i) const { return value < i.getValue(); }
};

int main(void){
    // Current knapsack, current list of all items, matrix of items picked per test case.
    vector<Item> K, I;
    vector<vector<Item>> R;
    // Capacity, Number of Objects, Value, Weight, Total Acquired Weight.
    int c, n, v, w;
    int t_w = 0;
    
    // Reading from Kattis.
    long long a, b;    
    while (cin >> a >> b) {
        // Read meta.
        cin >> c;
        cin >> n;
        // Read items.
        for(int i=0; i < n; i++){
            cin >> v;
            cin >> w;
            I.push_back(Item(v,w,i));
        }
        
        // Sort with highest value first.
        sort(I.rbegin(),I.rend());

        // Greedily pick the best items.
        for(int i=0; i < n; i++){
            if(t_w + I[i].getWeight() == c){ K.push_back(I[i]); t_w += I[i].getWeight(); break; } // Break if we're full.
            if(t_w + I[i].getWeight() < c){ K.push_back(I[i]); t_w += I[i].getWeight(); } // Add if we're not.
        }

        // Append the current knapsack to the knapsack matrix.
        R.push_back(K);
    }

    // Print number of picked objects.
    for(int i=0; i < R.size(); i++)
        cout << R[i].size();
    
    // Print the picked objects.
    for(int i=0; i < R.size(); i++){
        for(int j=0; j < R[i].size(); j++)
            cout << R[i][j].getIndex();
    }

    // Terminate the program.
    return 0;
}