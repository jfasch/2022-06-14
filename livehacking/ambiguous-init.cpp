#include <vector>
#include <iostream>
#include <string>

using namespace std;

int main()
{
    vector<int> v1(5,2);
    for (auto elem: v1)
        cout << elem << endl;

    vector<int> v2{5,2};
    for (auto elem: v2)
        cout << elem << endl;

    vector<string> v3{5,"hallo"};
    for (auto elem: v3)
        cout << elem << endl;

    return 0;
}
