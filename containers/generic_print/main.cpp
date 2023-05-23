#include<iostream>
#include<string>
#include<sstream>
#include<vector>
#include<list>

using namespace std;

template<typename T> 
void gen_delimiter(const T &container,ostream& o,const string &delim=" ") {
    int sz =  size(container);
    int count=0;
    for(auto value : container) {
        if(count < sz-1){
            o << value << delim;
        }
        count++;
    }
    o << container[sz-1];
    o << endl;
}

template<typename T> 
void gen_print(const T &container,ostream& o) {
    for(auto value : container) {
        o << value << " ";
    }
    o << endl;
}

template<typename T,typename T2>
T get_last(const T2 &container) {
    return *(container.rbegin());
}

auto auto_get_last(auto &container) {
    return *(container.rbegin());
}

int main() {
    ostringstream os;
    vector<int> int_vec = {10,9,8,7};
    vector<int> int2_vec = {10};
    vector<char> char_vec = {'a','b','c'};
    int int_ar[] = {1,2,3,4,5};
    char char_ar[] = {'x','y','z'};
    list<char> char_list = {'a','b','c'};
    list<string> string_list = {"first","second","third"};
    list<int> int_list = {1,2,3};

    gen_print(int_vec,os);
    gen_print(int2_vec,os);
    gen_print(char_vec,os);
    gen_print(int_ar,os);
    gen_print(char_ar,os);
    gen_print(char_list,os);

    cout << os.str() << endl;

    cout << get_last<string,list<string>>(string_list) << endl;
    cout << get_last<int,list<int>>(int_list) << endl;
    cout << auto_get_last(int_list) << endl;

    return 0;
}
