#ifndef BAG_COPY_H
#define BAG_COPY_H

#include <vector>
#include <string>

class BagCopy
{
public:
    using Item = std::pair<std::string, int>;

    void insert(Item item)
    {
        _items.push_back(item);
    }

    const Item& find_by_int(int i) const
    {
        static const Item empty;
        const Item* rv = &empty;
        for (const auto& item: _items)
            if (item.second == i) {
                rv = &item;
                break;
            }
        return *rv;
    }

    unsigned remove_by_int(int i)
    {
        unsigned nremoved{};
        for (auto it=_items.begin(); it!=_items.end();)
            if (it->second == i) {
                it = _items.erase(it);
                ++nremoved;
            }
            else
                ++it;
        return nremoved;
    }

private:
    std::vector<Item> _items;
};

#endif
