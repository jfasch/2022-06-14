#ifndef BAG_UNIQUE_H
#define BAG_UNIQUE_H

#include <vector>
#include <memory>
#include <string>
#include <utility>


class BagUnique
{
public:
    using Item = std::pair<std::string, int>;

    void insert(std::unique_ptr<Item>&& item)
    {
        _items.push_back(std::move(item));
    }

    const Item* find_by_int(int i) const
    {
        for (auto it=_items.cbegin(); it!=_items.cend(); ++it)
            if ((*it)->second == i)
                return it->get();
        return nullptr;
    }

    size_t remove_by_int(int i)
    {
        size_t nremoved{};

        for (auto it=_items.begin(); it!=_items.end();) {
            if ((*it)->second == i) {
                ++nremoved;
                it = _items.erase(it);
            }
            else
                ++it;
        }
        return nremoved;
    }
    
private:
    std::vector<std::unique_ptr<Item>> _items;
};

#endif
