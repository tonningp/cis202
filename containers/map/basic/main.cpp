#include<iostream>
#include<map>

using namespace std;

int main() {
    map<string, int> statePopulation;

    // 2013 population data from census.gov
    statePopulation.emplace("ca", 38332521);
    statePopulation.emplace("az", 6626624);
    statePopulation.emplace("ma", 6692824);

    cout << "Population of California in 2013 is "
        << statePopulation["ma"]
        << "." << endl;
    for (const auto &[k,v] : statePopulation)
        std::cout << '[' << k << "] = " << v << "; ";
}