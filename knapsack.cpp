#include <iostream>
#include <vector>
#include <string>


class Item{    
    int value, weight;
    std::string name;

    public:
    Item( std::string n, int w, int v){ name = n; value = v; weight = w; }
    const int getValue() const{ return value; }
    const int getWeight() const{ return weight; }
    const std::string getName() const{ return name; }
};

class Knapsack{
    int capacity;
    int weight = 0;
    std::vector<Item> items;

    public:
    Knapsack(const int c){ capacity = c; }
    
    void add(Item i){ 
        if(weight+i.getWeight() <= capacity){
            items.push_back(i); 
            weight += i.getWeight();
            std::cout << "Added " << i.getName() << " to the knapsack." << std::endl;
        } else
            std::cout << i.getName() << " is too heavy to fit in the knapsack." << std::endl;        
    }

    const std::vector<Item>& getItems() const { return items; }
    const int getCapacity() const { return capacity; }
};

int main(){
    Item gold_bar("Gold Bar", 100, 2000);
    Item dates("Dates", 20, 5);
    Knapsack k(100);
    k.add(gold_bar);
    k.add(dates);
    return 0;
}