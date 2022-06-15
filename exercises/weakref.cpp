#include <iostream>
#include "bag-shared.h"

using namespace std;

int main()
{
    BagShared bag;
    weak_ptr<BagShared::Item> weakref_joerg = bag.insert(make_shared<BagShared::Item>("joerg", 666));
    weak_ptr<BagShared::Item> weakref_caro = bag.insert(make_shared<BagShared::Item>("caro", 42));

    if (shared_ptr<BagShared::Item> joergref = weakref_joerg.lock())
        cout << joergref->first << ':' << joergref->second << endl;

    bag.remove_by_int(666);

    if (shared_ptr<BagShared::Item> joergref = weakref_joerg.lock())
        cout << joergref->first << ':' << joergref->second << endl;
    else
        cout << "weg isser" << endl;

    return 0;
}
