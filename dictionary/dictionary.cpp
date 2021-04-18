#include <iostream>
#include <array>

struct Item {
    std::string key;
    std::string value;
    Item* next;
};

class DictionaryUnsortedList {
private:
    std::array<Item*, 50> dict;

private:
    int hash(std::string const& s) {
        int hash = 5381;
        for (auto c : s) {
            hash = (hash << 5) + hash + c; /* hash * 33 + c */
        }
        return hash % 50;
    }

public:
   Item* insert(std::string const& key, std::string const& value) {
        Item* newItem = new Item();
        newItem->key = key;
        newItem->value = value;
        auto index = hash(key);
        if(!this->dict[index]) {
            this->dict[index] = newItem;
        } else {
            auto current = this->dict[index];
            while(current->next) {
                current = current->next;
            }
            current->next = newItem;
        }
        return newItem;
   }
   Item* retrieve(std::string const& key) {
        auto index = hash(key);
        if(!this->dict[index]) return nullptr;
        if(this->dict[index]->key == key) {
            return this->dict[index];
        } else {
            auto current = this->dict[index];
            while(current->next) {
                if(current->key == key) return current;
            }
            return nullptr;
        }
   } 
};
